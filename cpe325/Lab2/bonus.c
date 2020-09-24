#include <stdio.h>
#include <msp430.h>
#define ARR_SIZE 8                                                  // max array size

void printArr(int[ARR_SIZE][ARR_SIZE]);                             // printArray function prototype

int main()                                     
{
    WDTCTL = WDTPW + WDTHOLD;

    int arr1[ARR_SIZE][ARR_SIZE] =                                  // declare array 1
    {                                      
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8}                                      
    };                                     

    int arr2[ARR_SIZE][ARR_SIZE] =                                  // declare array 2
    {                                      
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,9}                                      
    };                                     

    int result[ARR_SIZE][ARR_SIZE];                                 // declare result array

    for(int i=0; i<ARR_SIZE; i++)                                   // begine multiplying with a for loop
    {                                      
        for(int j=0; j<ARR_SIZE; j++)                               // inner for loop 
        {                                      
            result[i][j] = 0;                                       // store 0 into result array as placeholder
            for(int k=0; k<ARR_SIZE; k++)                                      
            {                                      
                result[i][j] += arr1[i][k] * arr2[k][j];            // multiply and store
            }                                      
        }                                      
    }                                      
    
    printArr(result);                                               // call printArr function 

    return 0;                                      
}                                      

void printArr(int arr[ARR_SIZE][ARR_SIZE])                          // declare printArr function
{
    for(int i=0; i<ARR_SIZE; i++)
    {
        for(int j=0; j<ARR_SIZE; j++)
        {
            printf("%d", arr[i][j]);
            if(i != ARR_SIZE-1 || j != ARR_SIZE-1)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
