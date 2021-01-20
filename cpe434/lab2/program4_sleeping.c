// Sleeping Beauty

#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    sleep(60);
    printf("I am awake\n");
    return 0;
}