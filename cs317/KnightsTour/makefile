# CPE 212 Spring 2019 Project03 makefile
#
CC=g++
#CC=g++ -fprofile-arcs -ftest-coverage

KnightsTour: main.o 
	$(CC) main.o -o KnightsTour

main.o: main.cpp 
	$(CC) -c main.cpp


clean: 
	rm *.o KnightsTour

