#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 255

int main()
{
    
    for(;;)
    {
        char *buffer = malloc((BUFFER_SIZE)*sizeof(char)); // holds the command eneterd by the user
        printf("\n$");
        fgets(buffer, BUFFER_SIZE, stdin); // get the input
        buffer[strcspn(buffer, "\n")] = 0; // remove the trailing newline character 

        char **stringArray = malloc((BUFFER_SIZE)*sizeof(char*)); // allocate a 2d array to store the stringArrayized command
        for (int i = 0; i < (BUFFER_SIZE); i++)
            stringArray[i] = malloc((BUFFER_SIZE)*sizeof(char));

        /* 1: right redirect
           2: left redirect */ 
        int *redirect = malloc(sizeof(int));
        int *redirectDestination = malloc(sizeof(int));
        int *pipeFlag = malloc(sizeof(int)); // couts the number of pipes

        int argCount = 0; // generic counter
        *pipeFlag = 0; // counts number of pipes
        *redirect = 0; 

        stringArray[0] = strtok(buffer, " "); // begin breaking up the string
        while (stringArray[argCount] != NULL) 
        {
            stringArray[++argCount] = strtok(NULL, " ");
            if (stringArray[argCount] != NULL && strcmp(stringArray[argCount], ">") == 0) // handle right redirect
            {
                *redirect = 1;
                stringArray[argCount] = strtok(NULL, " ");
                *redirectDestination = open(stringArray[argCount], O_CREAT|O_RDWR|O_TRUNC, 0644); // create a file with read write permissions and truncate to 0
                argCount--;
            }
            else if ((stringArray[argCount] != NULL) && (strcmp(stringArray[argCount], "<") == 0)) // handle left redirect
            {
                *redirect = 2;
                stringArray[argCount] = strtok(NULL, " ");
                *redirectDestination = open(stringArray[argCount], O_CREAT|O_RDWR|O_TRUNC, 0644); // create a file with read write permissions and truncate to 0
                argCount--;
            }
            else if ((stringArray[argCount] != NULL) && (strcmp(stringArray[argCount], "|") == 0)) // handle pipes
                *pipeFlag = argCount;
        }
        stringArray[argCount] = NULL;

        if (stringArray[0] != NULL && strcasecmp(stringArray[0], "exit") == 0) 
    {
        printf("Goodbye\n");
        exit(0);
    }

    if (*pipeFlag == 0) 
    {
        pid_t pid = fork();
        if (pid > 0) // parent waits for the child
            wait(0);
        
        else if (pid == 0) // child executes
        { 
            if (*redirect == 0) 
                execvp(stringArray[0], stringArray);
            
            else if (*redirect == 1 && *redirectDestination != -1) // if right redirect and an error has not occured
            {
                dup2(*redirectDestination, 1);
                execvp(stringArray[0], stringArray);
            }
            else if (*redirect == 2 && *redirectDestination != -1) // if left redirect and an error has not occured
            {
                dup2(*redirectDestination, 0);
                execvp(stringArray[0], stringArray);
            }
            else if (*redirectDestination == -1) // if an error has occured
            {
                printf("Could not create file.\n");
                exit(-1);
            }
            exit(0);
        }
        else 
        { 
            printf("Error! Could not create child.\n");
            exit(-1);
        }
    }
    else 
    {
        /* pipeDes[0]: file descriptor for the read end of pipe
           pipeDes[1]: file descriptor for the write end */
        int pipeDes[2]; 
        if (pipe(pipeDes) == -1) 
            printf("Pipe Ded\n");
        else 
        {
            char* leftProgram[BUFFER_SIZE]; // holds the left end of the pipe
            char* rightProgram[BUFFER_SIZE]; // holds the right end of the pipe
            int i;
            int j = 0;

            for(i = 0; i < argCount; i++) // populate the left and right program buffers
            {
                if (i < *pipeFlag) // populate the left buffer
                    leftProgram[j++] = stringArray[i];
                
                else if (i == *pipeFlag) 
                {
                    leftProgram[j] = NULL;
                    j = 0;
                }
                else if (i > *pipeFlag) // populate right program
                {
                    leftProgram[j++] = stringArray[i];
                }
            }
            rightProgram[j] = NULL;
            int pid = fork();
            if (pid == 0) // execute the left program
            {
                dup2(pipeDes[1], 1);
                close(pipeDes[0]);
                execvp(leftProgram[0], leftProgram);
                printf("Error 1\n");
                exit(1);
            }

            pid = fork();
            if (pid == 0) // execute the right program
            {
                dup2(pipeDes[0], 0);
                close(pipeDes[1]);
                if (*redirect > 0)
                    dup2(*redirectDestination, 1);
                execvp(rightProgram[0], rightProgram);
                printf("Error 2\n");
                exit(1);
            }

            close(pipeDes[1]);
            close(pipeDes[0]);
            wait(0);
            wait(0);
        }
    }

        free(buffer);
        free(stringArray);
        free(redirect);
        free(redirectDestination);
        free(pipeFlag);
    }
    return 0;
}
