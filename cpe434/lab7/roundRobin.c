#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Process
{
    int pid; // process ID
    int burst_time; // CPU Burst Time
    int working_time; // time this process executed, if working_time == burst_time, process is complete
    int t_round; // turn around time, time needed for the process to complete 
    int sleep_time;
}Process; 

int promptUser(char *); // prompt the user for input, return it as an integer
int populateArray(Process [], int); // popuate the process array
int checkID(Process [], int); // check for duplicate id's in the process array
void removeFromList(Process [], int, int);

int main()
{
    int processNum = promptUser("Enter the number of processes.\n");
    int quantumTimeUnit = promptUser("Enter the quantum time unit.\n");

    Process todo[processNum];
    Process done[processNum];

    int processListSize = populateArray(todo, processNum); 

    printf("-------------\n");
    printf("Time (ms) PID\n");

    int elapsedTime = 0;
    int i, ii; // i-index for todo, ii-index for done

    while(processListSize != 0)
    {
        int remainingTime = todo[i].burst_time - todo[i].working_time; 
        if(remainingTime < quantumTimeUnit) // if the process has run out of time to execute
        {
            elapsedTime += remainingTime;
            todo[i].working_time += remainingTime;
            todo[i].t_round += elapsedTime - todo[i].sleep_time;
            printf("%5d", remainingTime);
        }
        else
        {
            elapsedTime += quantumTimeUnit;
            todo[i].working_time += quantumTimeUnit;
            todo[i].t_round += elapsedTime - todo[i].sleep_time;
            printf("%5d", quantumTimeUnit);
        }

        printf("%7d\n", todo[i].pid);

        if(todo[i].working_time >= todo[i].burst_time) 
        {
            done[ii] = todo [i];
            ii++;
            removeFromList(todo, i+1, processListSize);
            processListSize--;
            i--;
        }
        else    
            todo[i].sleep_time = elapsedTime;

        if(++i >= processListSize)
            i = 0;
    }

    double averageWait = 0;
	double averageTurnaround = 0;
	for (int i = 0; i < ii; i++) 
    {
		averageWait += done[i].t_round - done[i].working_time;
		averageTurnaround += done[i].t_round;
		printf("\nProcess %d finished executing after %d ms.\n", done[i].pid, done[i].t_round);
		printf("Work Time: %d ms\n", done[i].working_time);
		printf("Wait Time: %d ms\n", done[i].t_round - done[i].working_time);
	}
	averageWait = averageWait/ii;
	averageTurnaround = averageTurnaround/ii;
	printf("\nAverage wait time: %.3f ms\n", averageWait);
	printf("Average turn-around time: %.3f ms\n\n", averageTurnaround);

    
    return 0;
}

int promptUser(char *prompt)
{
    printf("%s", prompt);
    char string[200];
    fgets(string, 200, stdin); // get the user input
    string[strcspn(string, "\n")] = 0; // remove th endline character
    return atoi(string); // return an interger version of the input
}


int checkID(Process processList[], int index)
{
    int process = processList[index].pid; // get the pid at the specified index
    for(int i=0; i<index; i++)
    {
        if(process == processList[i].pid)
        {
            printf("%d has already been used.\n Cannot have two of the same PID.\n", process);
            return -1;
        }
    }
    return 0;
}


int populateArray(Process list[], int num)
{
    int size = 0;
    for(int i=0; i<num; i++)
    {
        list[i].pid = promptUser("Enter a new ID.\n");
        while(checkID(list, i) == -1) // keeps user from entering a repeat ID
            list[i].pid = promptUser("Enter a new ID.\n");
        
        size++;

        list[i].burst_time = promptUser("Enter the burst time.\n");
        list[i].working_time = 0;
        list[i].t_round = 0;
        list[i].sleep_time = 0;
    }
    return size;
}


void removeFromList(Process processList[], int index, int n)
{
    for(int i=index-1; i<n; i++)
        processList[i] = processList[i+1];
}


