// Program 1

#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int val = 0;

    pid = fork();
    if(pid == 0)
    {
        val += 2;
        printf("The value of val is %d. The PID is %d\n", val, getpid());
        return 0;
    }

    wait(NULL);
    val += 5;
    printf("The value of val is %d. The PID is %d\n", val, getpid());
    return 0;
}