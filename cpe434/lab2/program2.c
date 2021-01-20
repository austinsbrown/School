// Program 2

#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h>

int sub(int, int);
int add(int, int);
int mul(int, int);

int main()
{
    pid_t pPID, cPID;
    int result;
    int status = 0;
    
    printf("The parent PID is %d\n", getpid());
    pPID = fork();

    if(pPID == 0)
    {
        result = sub(5,2);
        printf("I am child 1.\n");
        printf("The result is %d and the PID is %d\n", result, getpid());
        cPID = fork();
        if(cPID == 0)
        {
            result = add(2,2);
            printf("I am child 2.\n");
            printf("The result is %d and the PID is %d\n", result, getpid());
            exit(0);
        }
        while ((pPID = wait(&status)) > 0);                             // wait for the child to finish
        result = mul(2,6);
        printf("I am child 1\n");
        printf("The result is %d and the PID is %d\n", result, getpid());
        exit(0);
    }
    while ((pPID = wait(&status)) > 0);                             // wait for the child to finish
    printf("The parent has finished executing.\n");
    return 0;
}


int sub(int arg1, int arg2)
{
    int result = arg1 - arg2;
    return result;
}

int add(int arg1, int arg2)
{
    int result = arg1 + arg2;
    return result;
}

int mul(int arg1, int arg2)
{
    int result = arg1 * arg2;
    return result;
}