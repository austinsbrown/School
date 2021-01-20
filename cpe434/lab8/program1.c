#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void protect(int); 
void killChild(int);
void sendAlarm(int);
void killParent(int);

pid_t pid;

int main()
{
    pid = fork(); // create a child process

    if(pid == 0) // the child executes this
    {
        printf("The child is now executing with a PID of %d\n", getpid());
        signal(SIGINT, protect); // keeps ctr-c from working
        signal(SIGUSR1, killChild); // SIGUSR1 triggers kill child
    }
    else // the parent executes this
    {
        printf("The parnet is now executing with a PID of %d\n", getpid());
        signal(SIGINT, protect); // keeps ctr-c from working
		signal(SIGALRM, sendAlarm); // SIGALRM triggers the send alarm function
		alarm(10); 
    }

    for(;;);
    return 0;
}

void protect(int signal)
{
    if(pid == 0)
        printf("Child %d has been protected\n", getpid());
    else
        printf("Parent %d has been protected.\n", getpid());
}


void killChild(int signal)
{
    printf("Killing process %d\n", getpid());
    exit(0);
}


void sendAlarm(int sig)
{
    printf("The parent can now be killed with ctr-c.\n");
	signal(SIGINT, killParent);
}


void killParent(int sig)
{
    kill(pid, SIGUSR1);
    wait(0);
    printf("killing parent.\n");
    exit(0);
}