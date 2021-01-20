#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#define ARRSZE 340000000

typedef struct stride // will have a stride of 8 bytes instead for 5 if compiler optimizes for execution speed
{
    int a;
    char b;
}stride;

int main()
{
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);

    stride *ptr = (stride*)malloc(ARRSZE*sizeof(stride));

    for(int i=0; i<ARRSZE; i++)
    {
        ptr[i].a = 0;
        ptr[i].b = 0;
    }

    clock_gettime(CLOCK_REALTIME, &stop);
    unsigned long long totalSeconds = (long long)(stop.tv_sec - start.tv_sec);
    unsigned long totalNanoseconds = stop.tv_nsec - start.tv_nsec;

    printf("Total execution time: %llu.%.9lu\n", totalSeconds, totalNanoseconds);


    free(ptr);
    return 0;
}