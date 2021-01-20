// Program 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    if(n % 2 != 0)
    {
        printf("The input must be an even number!\n");
        return 0;
    }

    pid_t pPID, cPID;

    pPID = getpid();                                                // get the parents pid
    printf("The parent's PID is %d\n\n", getpid());
    for(int i=0; i<n-1; i++)
    {
        cPID = fork();
        if(pPID == getpid())
        {
            printf("The child's PID is %d\n\n", cPID);
        }

        else if(cPID == 0)
            exit(0);
    }
    return 0;
}