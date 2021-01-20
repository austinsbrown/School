#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid; // holds a pid
    int x = 0; // variable to test

    printf("Parent prints address of x: %p\n", (void*)&x); // print the address of x 
    printf("Value of x: %d\n", x); // print the value of x
    pid = fork(); // create new child process

    if(pid == 0) // child runs this
    {
        printf("Child prints the address of x: %p\n", (void*)&x);
        printf("Value of x: %d\n", x);
        printf("x is now being set to 10.\n");
        x = 10; // change the value of x
        printf("Child prints the address of x: %p\n", (void*)&x);
        printf("Value of x: %d\n", x);
        exit(0); // exit the child process
    }

    else
    {
        wait(0); // child prints first 
        printf("Parent prints address of x: %p\n", (void*)&x);
        printf("Value of x: %d\n", x);
        printf("x is now being set to -2.\n");
        x = -2; // change the value of x
        printf("Parent prints address of x: %p\n", (void*)&x);
        printf("Value of x: %d\n", x);
    }
    return 0;
}