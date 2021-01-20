#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int identifier; // holds a address
    int i; // generic counter
    SharedData *control; // info struct
    char buffer[255]; // holds the user input

    strcpy(buffer, "NO"); 
 
    /* 
       allocates shared mem segment
       key of 1234 is passed in as first arg
       size of the struct is passed in as second arg
       IPC_CREAT | 0666 sets it to read write 
    */
    if((identifier = shmget(KEY, STRUCTSIZE, IPC_CREAT | 0666)) < 0) // check for errors
    {
        printf("An error has occured. Could not create memory segment.\n");
        exit(-1);
    }

    if ((control = (SharedData*) shmat(identifier, 0, 0)) <= (SharedData*)(0)) 
    {
        printf("Error: Failed to attach address space to shared memory. Terminating...\n");
        exit(1);
    }   
    
    control->flag = 2; // waiting on process 2
    printf("Waiting for process 2.\n");
    while (control->flag == 2);
    printf("Ack from process 2 recieved.\n");

    while(control->flag != -1)
    {
        if(strcasecmp(buffer, "Y") == 0 || strcasecmp(buffer, "YES") == 0) // exit the program?
        {
           control->flag = -1; 
        }

        else if(strcasecmp(buffer, "N") == 0 || strcasecmp(buffer, "NO") == 0) // repeat the process
        {
            printf("Enter the value for 1: ");
            scanf("%s", buffer);
            control->value1 = atoi(buffer);
            printf("\nEnter the value for 2: ");
            scanf("%s", buffer);
            control->value2 = atoi(buffer);
            control->flag = 1;
        }

        if(control->flag != -1) // exit the program.
        {
            while(control->flag != 0);
            printf("\nType yes if you want to exit the program.\n");
            printf("Type no if you don't want to exit\n");
            fgets(buffer, 255, stdin);
            buffer[strcspn(buffer, "\n")] = 0;

            while(!(strcasecmp(buffer, "Y") == 0 || strcasecmp(buffer, "YES") == 0) && !(strcasecmp(buffer, "N") == 0 || strcasecmp(buffer, "NO") == 0))
            {
                printf("yes/no\n");
                fgets(buffer, 255, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
            }
        }
    }
    shmdt(control); // detach shared memory space
    shmctl(identifier, IPC_RMID, NULL); // mark shared memor space for deletion
    return 0;
}