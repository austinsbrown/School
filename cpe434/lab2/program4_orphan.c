// Orphan

#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if(pid == 0)
    {
        printf("This is the child. My PID is %d\n", getpid());
        sleep(5);
        printf("This is the child. My PID is %d\n", getpid());
        exit(0);
    }

    printf("I am the parent. My PID is %d\n\n", getpid());
    return 0;
}