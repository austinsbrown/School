#include "sortingAlgorithims.h"

#define ARRSZE 50000000
//#define ARRSZE 160000

int main()
{
    int *arr = generateArray(ARRSZE);
    //insertionSort(arr, ARRSZE);
    //mergeSort(arr, 0, ARRSZE-1);
    quickSort(arr, 0, ARRSZE-1);


    int x = check(arr, ARRSZE);
    if(x)
        printf("Sorted!\n");
    else
        printf("Not Sorted!\n");

    free(arr);
    return 0;
}