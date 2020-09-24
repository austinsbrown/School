// *************************************************************************
// Program File:                main.cpp
// Name:                        Austin Brown
// Course Section:              CS-317-03
// Due Date:                    11/24/19
// Program Description:         The user inputs the size of a chessboard 
//                              and a set of coordinates. The program then 
//                              attempts to find a knight's tour solution.
// *************************************************************************

#include <iostream>
using namespace std;

const int POSSIBLEMOVES = 8;                                                    // number of possible moves                                  
const int rowMoves[POSSIBLEMOVES] = {2, 1, -1, -2, -2, -1, 1, 2};               // possible horizontal moves
const int colMoves[POSSIBLEMOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};               // possible vertical moves


void printBoard(int **, int);                                                   // function to print a 2d array
bool findTour(int **, int, int, int, int);                                      // function to find a possible tour                          


int main() 
{
    int size, startRow, startCol;                                               // size of the board, starting row, starting column

    cout << "Enter the size of the board: ";        
    cin >> size;                                                                // get the size of the board

    cout << "Enter the starting row: ";
    cin >> startRow;                                                            // get the starting row

    cout << "Enter the starting column: ";
    cin >> startCol;                                                            // get the starting column
    cout << endl;

    int** board = new int*[size];                                               // allocate space for a 2d array
    for(int i = 0; i < size; ++i)
        board[i] = new int[size];

    for (int row = 0; row < size; row++)                                        // initialize the array to 0
        for (int col = 0; col < size; col++)
            board[row][col] = 0;

    board[startRow][startCol] = 1;                                              // set the starting loaction to 1
    if (findTour(board, size, 1, startRow, startCol))                           // attempt to find a tour
        printBoard(board, size);                                                // if one is found, print the board
    else
        cout << "Failed to find a tour!\n";

    cout << endl;
    
    for(int i = 0; i < size; i++)                                               // deallocate the space held by the board array
        delete[] board[i];
    delete[] board;

    return 0;
}


void printBoard(int **arr, int n)                                               
{
    for (int i = 0; i < n; i++)                                                 // outer loop for rows in the array
    {
        for (int j = 0; j < n; j++)                                             // inner loop for columns in the array
        {
            if (arr[i][j] < 10)                                                 // handle spacing
                cout << ' ';
            cout << arr[i][j] << ' ';
        }
        cout << endl;                                                           // out put the element
    }
}


bool findTour(int **arr, int n, int moveNumber, int currentRow, int currentCol) 
{

    if (moveNumber == n * n)                                                    // if current move number is the area of the board,
        return true;                                                            // the tour is done

    for (int move = 0; move < POSSIBLEMOVES; move++)                            // attempt different moves
     {
        int newRow = currentRow + rowMoves[move];                               // calculate the next row move
        int newCol = currentCol + colMoves[move];                               // calculate the next col move

        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)             // check to see if the move exceeds the boards boundries
            continue;

        if (arr[newRow][newCol] != 0)                                           // check to see if the next move has already been used
            continue;

        arr[newRow][newCol] = moveNumber + 1;                                   // if all checks are passed, assign a number to the board
        if (findTour(arr, n, moveNumber + 1, newRow, newCol))                   // recursive call
            return true;
            
        arr[newRow][newCol] = 0;                                                // reset the board
    }
    return false;
}
