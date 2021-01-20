// Zombie

#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    if (fork () > 0)
    {
    printf("I am the parent.\n");
    sleep(50);
    }
    return 0;
}