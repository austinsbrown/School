#include "sortingAlgorithims.h"

int *generateArray(long int n) 
{
	srand(time(NULL));
	int *arr = (int*)malloc(n * sizeof(int));
	long int i;
	for (i = 0; i < n; i++) 
		arr[i] = rand();
	return arr;
}

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mergeArrays(int *arr, int l, int m, int r) 
{
	long int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	//int leftArr[n1], rightArr[n2];
	int *leftArr = (int*)malloc(n1*sizeof(int));
	int *rightArr = (int*)malloc(n2*sizeof(int));
	
	// Copy data from arr into temp arrays
	for (i = 0; i < n1; i++)
		leftArr[i] = arr[l+i];
	for (j = 0; j < n2; j++)
		rightArr[j] = arr[m+1+j];
		
	i = 0;
	j = 0;
	k = l;
	// Merge temp arrays back into arr
	while (i < n1 && j < n2) 
	{
		if (leftArr[i] <= rightArr[j])
			arr[k++] = leftArr[i++];
		else 
			arr[k++] = rightArr[j++];
	}
	
	// Copy remaining elements of leftArr into arr
	while (i < n1) 
		arr[k++] = leftArr[i++];
		
	// Copy remaining elements of rightArr into arr
	while (j < n2)
		arr[k++] = rightArr[j++];

	free(leftArr);
	free(rightArr);
}

void mergeSort(int *arr, long int l, long int r) 
{
	if (l < r) 
	{
		long int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		mergeArrays(arr, l, m, r);
	}
}

void insertionSort(int *arr, long int n) 
{
	long int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int partition(int *arr, long int l, long int h) 
{
	int pivot = arr[h];
	long int i = (l - 1);
	
	long int j;
	for (j = l; j <= h-1; j++) 
	{
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return (i+1);
}

void quickSort(int *arr, long int l, long int h) 
{
	if (l < h) 
	{
		int pIndex = partition(arr, l, h);
		quickSort(arr, l, pIndex-1);
		quickSort(arr, pIndex+1, h);
	}
}

int check(int *arr, long int n) 
{
	long int i;
	int temp = arr[0];
	for (i = 1; i < n; i++) 
	{
		if (temp > arr[i])
			return 0;
		temp = arr[i];
	}
	return 1;
}