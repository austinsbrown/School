CC = gcc

parallel: parallel.c serial.c
	$(CC) parallel.c -o parallel -lm -lpthread
	$(CC) serial.c -o serial -lm

clean:
	rm serial parallel
