#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: ./b.out intervals\n");
        exit(-1);
    }

    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start); // start timer

    int intervals = atoi(argv[1]);
    if(intervals < 0)
    {
        printf("Interval needs to be greater than 0.\n");
        exit(-1);
    }

    double width = (double)1/intervals;
	double sum = 0;
	double temp1, temp2;
	int i = 0;

	temp1 = sqrt(1 - pow(i * width, 2));
	for (i = 0; i < intervals; i++) 
    {
		temp2 = sqrt(1 - pow((i+1) * width, 2));
		sum += ((temp1 + temp2) / 2) * width;
		temp1 = temp2;
	}


    sum *= 4;

    clock_gettime(CLOCK_REALTIME, &stop);
    unsigned long long totalSeconds = (long long)(stop.tv_sec - start.tv_sec);
	unsigned long totalNanoseconds = stop.tv_nsec - start.tv_nsec;
	printf("Execution Time: %llu.%.9lu\n", totalSeconds, totalNanoseconds);
	printf("Final Calculation: %.12f\n", sum);

    return 0;
}