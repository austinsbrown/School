CC = gcc

default:
	make priority
	make roundRobin

roundRobin: roundRobin.c
	$(CC) roundRobin.c -o roundRobin
	
priority: priority.c
	$(CC) priority.c -o priority

clean:
	rm roundRobin priority