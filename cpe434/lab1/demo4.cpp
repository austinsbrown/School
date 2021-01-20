#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();

    if(pid==0)
    {
        printf("I am child, my Id is %d\n",getpid()); 
        printf("i am child, my parent is %d\n",getppid());
        printf("Child is sleeping for	10 seconds until when the parent might be dead already\n");
        sleep(10);
        printf("I am the same child with Id %d, but my parent id is %d",getpid(),getppid());
    }
    else
    {
        printf("I am the parent with id %d. My parent is %d and child is %d\n",getpid(),getppid(),pid); 
        sleep(5);
    }
}

