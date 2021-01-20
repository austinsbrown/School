#include <iostream>
#include <time.h>
using namespace std;

#define ARRSZE 20000

int main()
{
    struct timespec start, stop;
	clock_gettime(CLOCK_REALTIME, &start);

    int** array = new int*[ARRSZE];                                              
    for(int i = 0; i < ARRSZE; ++i)
        array[i] = new int[ARRSZE];

    int i,j; 
    for(i=0;i<ARRSZE;i++)
        for(j=0;j<ARRSZE;j++)
            array[j][i]=0; // cause cache misses

    for(int i = 0; i < ARRSZE; i++)                                               
        delete[] array[i];
    delete[] array;

    clock_gettime(CLOCK_REALTIME, &stop);
	unsigned long long totalSeconds = (long long)(stop.tv_sec - start.tv_sec);
	unsigned long totalNanoseconds = stop.tv_nsec - start.tv_nsec;

	printf("Total execution time: %llu.%.9lu\n", totalSeconds, totalNanoseconds);
    return 0;
}
