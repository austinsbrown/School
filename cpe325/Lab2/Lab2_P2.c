#include <stdio.h>
#include <msp430.h>

int *processArray(int [], int, int, int);
void printArray(int [], int);

int main()
{
    WDTCTL = WDTPW + WDTHOLD;

    int input[] = {-1, 2, 5, 3, 5, 6};                  // declare input array
    int m = 2;                                          // delcare m constant
    int c = 0;                                         // delcare c constant

    int inputSize = sizeof(input) / 2;                  // get size of array

    printf("Input Array X: ");                          // print the original array
    printArray(input, inputSize);                       

    printf("Input Constants m: %d and c: %d\n", m, c);  // print constants
    printf("Output array Y: ");

    int *result;
    result = processArray(input, inputSize, m, c);

    printArray(result, inputSize);

    return 0;
}


int *processArray(int arr[], int inputSize, int m, int c)
{
    for(int i=0; i<inputSize; i++)                      // multiply for loop
    {
        arr[i] = arr[i] * m;                            // multiply
        arr[i] = arr[i] + c;                            // add
    }
    return arr;
}


void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)                           // print new array
    {
        printf("%d", arr[i]);                           // print elements in array
        if(i < size-1)                                  // keeps comma from being added after last element
        {
            printf(", ");                                // print comma
        }
    }
    printf("\n");  
}
