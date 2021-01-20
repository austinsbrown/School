#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int * generateArray(long int);
void swap(int *, int *);
void mergeArrays(int *, int, int, int);
void mergeSort(int *, long int, long int);
void insertionSort(int *, long int);
int partition(int *, long int, long int);
void quickSort(int *, long int, long int);
int check(int *, long int);