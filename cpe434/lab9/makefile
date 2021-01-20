CC = gcc

csa: checkSortingAlgorithims.o sortingAlgorithims.o
	$(CC) checkSortingAlgorithims.o sortingAlgorithims.o -O0 -o csa

checkSortingAlgorithims.o: checkSortingAlgorithims.c sortingAlgorithims.h
	$(CC) -c checkSortingAlgorithims.c

sortingAlgorithims.o: sortingAlgorithims.c sortingAlgorithims.h
	$(CC) -c sortingAlgorithims.c

clean:
	rm *.o csa