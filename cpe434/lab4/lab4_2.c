#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int identifier;
    SharedData *control;

    if((identifier = shmget(KEY, STRUCTSIZE, 0)) < 0) // get the identifier of the space
    {
        printf("Could not find memory segment.\n");
        exit(-1);
    }

    control = (SharedData*)shmat(identifier, 0, 0); // attach the sheared space
    if(control <= (SharedData*)(0))
    {
        printf("Could not attach to shard memory.\n");
        exit(-1);
    }

    control->flag = 2;
    while(control->flag != -1) // do math
    {
        if(control->flag == 1)
        {
            control->sum = control->value1 + control->value2;
            printf("%f + %f = %f\n", control->value1, control->value2, control->sum);
            control->flag = 0;
            printf("Waiting for process 1.\n");
        }

        else if(control->flag == 2)
        {
            printf("Waiting for process 1.\n");
            control->flag = 0;
        }
    }
    printf("Exiting...\n");
    shmdt(control);
}