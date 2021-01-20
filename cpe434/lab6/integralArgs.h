typedef struct integralArgs
{
	int threadID;
    int threadCount; // total number of threads
	int intervalCount; // total number of intervals
	int intervalStart; // what interval each thread starts at
	int intervalsPerThread; 
	double width;
}integralArgs;