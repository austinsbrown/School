#include <stdio.h> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h>

using namespace std;

int main()
{
    printf("I am Parent\n"); 
    fork();
    printf("This by a parent and child\n"); 
    fork();
    printf("This should be 4 times\n"); 
    return 0;
}
