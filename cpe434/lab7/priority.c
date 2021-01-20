#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Process
{
    int pid; // process ID
    int priority;
    int burst_time; // CPU burst time
    int working_time; // time this process executed, if working_time==burst_time, process is complete
    int t_round; // turn around time, time needed for the process to complete 
}Process;

int promptUser(char *); // prompts the user for input
int checkID(int, Process []); // returns 0 if the process processList does not have a repeat, returns -1 otherwise
void sortPriorityprocessList(Process [], int); // sorts the priority processList based on priority
void getResults(Process [], int); // calculates results and prints them in table format

int main()
{
    int processNum = promptUser("Enter how many process that you need.\n"); 
    Process processList[processNum]; // processList of all of the processes 
    
    for(int i=0; i<processNum; i++)
    {
        processList[i].pid = promptUser("Enter a new ID.\n");
        while(checkID(i, processList) == -1) // keeps user from entering a repeat ID
            processList[i].pid = promptUser("Enter a new ID.\n");
        
        processList[i].priority = promptUser("Enter the priority of that process.\n");
        processList[i].burst_time = promptUser("Enter the burst time.\n");
        processList[i].working_time = 0;
        processList[i].t_round = 0;
    }

    sortPriorityprocessList(processList, processNum); // sort the processList
    getResults(processList, processNum); 

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


int checkID(int index, Process processList[])
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


void sortPriorityprocessList(Process processList[], int size)
{
    Process temp; // used for sorting
    for(int i=0; i<size-1; i++)
    {
        for(int ii=0; ii<size-1; ii++)
        {
            if(processList[ii].priority > processList[ii+1].priority) // if left element is greater than right element
            {
                temp = processList[ii]; // store i in a temp variable
                processList[ii] = processList[ii+1]; // swap ii and ii+1
                processList[ii+1] = temp;
            }
        }
    }
}


void getResults(Process list[], int num)
{
	printf("  Time (ms)       PID     \n");
	printf("--------------------------\n");
    int elapsedTime = 0;
	for (int i=0; i<num; i++) 
    {
		list[i].working_time += list[i].burst_time;
		list[i].t_round += list[i].burst_time;
		list[i].t_round += elapsedTime;
		elapsedTime += list[i].working_time;
		printf("  %5d", list[i].burst_time);
		printf(" %12d\n", list[i].pid);
		printf("--------------------------\n");
	}

    double averageWait = 0;
	double averageTurn = 0;
	for (int i=0; i<num; i++) 
    {
		averageWait += list[i].t_round-list[i].working_time;
		averageTurn += list[i].t_round;
		printf("\nProcess %d finished executing after %d ms.\n", list[i].pid, list[i].t_round);
		printf("	Work time: %d ms\n", list[i].working_time);
		printf("	Wait time: %d ms\n", list[i].t_round-list[i].working_time);
	}
	averageWait = averageWait/num;
	averageTurn = averageTurn/num;
	printf("\nAverage wait time: %.3f ms\n", averageWait);
	printf("Average turn-around time: %.3f ms\n\n", averageTurn);
}