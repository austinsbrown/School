#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void explode();
void escape();

int main() 
{
	signal(SIGINT, explode); 
	signal(SIGALRM, escape);
	for(;;);
}

void explode() 
{
	srand(time(NULL)); // set up seed 
	alarm(10);
	for(;;) 
		printf("%c", (rand()%(126-32))+32); // print random ascii stuff
}

void escape() 
{
	printf("\n");
	exit(0);
}