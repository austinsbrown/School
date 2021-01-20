#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 255

void getInput(char *); // gets the user input and stores to a string
int createToken(char *, char **, int *, int *, int *); // splits the input into tokens and counts the number of args
void execute(char **, int *, int *, int *, int); 

int main()
{
    
    for(;;)
    {
        char *buffer = malloc((BUFFER_SIZE)*sizeof(char)); // holds the command eneterd by the user
        getInput(buffer); // get the input and store to the buffer

        char **stringArray = malloc((BUFFER_SIZE)*sizeof(char*)); // allocate a 2d array to store the tokenized command
        for (int i = 0; i < (BUFFER_SIZE); i++)
            stringArray[i] = malloc((BUFFER_SIZE)*sizeof(char));

        /* 1: right redirect
           2: left redirect */ 
        int *reFlag = malloc(sizeof(int));
        int *reDes = malloc(sizeof(int));
        int *pipeFlag = malloc(sizeof(int)); // couts the number of pipes

        int argCount = createToken(buffer, stringArray, reFlag, pipeFlag, reDes);
        execute(stringArray, reFlag, pipeFlag, reDes, argCount);

        free(buffer);
        free(stringArray);
        free(reFlag);
        free(reDes);
        free(pipeFlag);
    }
    return 0;
}


void getInput(char *input)
{
    printf("\n$");
    fgets(input, BUFFER_SIZE, stdin); // get the input
    input[strcspn(input, "\n")] = 0; // remove the trailing newline character 
}


int createToken(char *buffer, char **token, int *redirect, int *pipe, int *redirectDestination) 
{
    int i = 0; // generic counter
    *pipe = 0; // counts number of pipes
    *redirect = 0; 

    token[0] = strtok(buffer, " "); // begin breaking up the string
    while (token[i] != NULL) 
    {
        token[++i] = strtok(NULL, " ");
        if (token[i] != NULL && strcmp(token[i], ">") == 0) // handle right redirect
        {
            *redirect = 1;
            token[i] = strtok(NULL, " ");
            *redirectDestination = open(token[i], O_CREAT|O_RDWR|O_TRUNC, 0644); // create a file with read write permissions and truncate to 0
            i--;
        }
        else if ((token[i] != NULL) && (strcmp(token[i], "<") == 0)) // handle left redirect
        {
            *redirect = 2;
            token[i] = strtok(NULL, " ");
            *redirectDestination = open(token[i], O_CREAT|O_RDWR|O_TRUNC, 0644); // create a file with read write permissions and truncate to 0
            i--;
        }
        else if ((token[i] != NULL) && (strcmp(token[i], "|") == 0)) // handle pipes
            *pipe = i;
    }
    token[i] = NULL;
    return i;
}


void execute(char **token, int *redirectFlag, int *pipeFlag, int *redirectDestination, int arg)
{
    if (token[0] != NULL && strcasecmp(token[0], "exit") == 0) 
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
            if (*redirectFlag == 0) 
                execvp(token[0], token);
            
            else if (*redirectFlag == 1 && *redirectDestination != -1) 
            {
                dup2(*redirectDestination, 1);
                execvp(token[0], token);
            }
            else if (*redirectFlag == 2 && *redirectDestination != -1)
            {
                dup2(*redirectDestination, 0);
                execvp(token[0], token);
            }
            else if (*redirectDestination == -1) 
            {
                printf("Failed to create file.\n");
                exit(-1);
            }
            exit(0);
        }
        else 
        { 
            printf("Error! Child failed to create!\n");
            exit(-1);
        }
    }
    else 
    {
        int pipeDes[2];
        if (pipe(pipeDes) == -1) 
            printf("Pipe Ded\n");
        else 
        {
            char* prog1[BUFFER_SIZE];
            char* prog2[BUFFER_SIZE];
            int i;
            int j = 0;

            for(i = 0; i < arg; i++) 
            {
                if (i < *pipeFlag) 
                    prog1[j++] = token[i];
                
                else if (i == *pipeFlag) 
                {
                    prog1[j] = NULL;
                    j = 0;
                }
                else if (i > *pipeFlag) 
                {
                    prog2[j++] = token[i];
                }
            }
            prog2[j] = NULL;
            int pid = fork();
            if (pid == 0) 
            {
                dup2(pipeDes[1], 1);
                close(pipeDes[0]);
                execvp(prog1[0], prog1);
                printf("Error 1\n");
                exit(1);
            }

            pid = fork();
            if (pid == 0)
            {
                dup2(pipeDes[0], 0);
                close(pipeDes[1]);
                if (*redirectFlag > 0)
                dup2(*redirectDestination, 1);
                execvp(prog2[0], prog2);
                printf("Error 2\n");
                exit(1);
            }

            close(pipeDes[1]);
            close(pipeDes[0]);
            wait(0);
            wait(0);
        }
    }
}
