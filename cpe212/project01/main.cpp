//
// main.cpp --  Project01, CPE212 Spring 2019 -- C++ Review Project
//
// Driver program for Image Processing Program which is used to test each
// image processing operation.
//
// Place the definitions for the missing functions into the file project01.cpp
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

// List of allowed include files appear below
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;                    // Global using declaration

// Global Constants -- you may use these global constants in your code
const int MAXROWS = 28;                 // Maximum number of rows in image
const int MAXCOLS = 28;                 // Maximum number of columns in image
const int LIMIT = 10;                   // Max number of records retrieved from data file

// Record for storing one line of data from input file
struct Record
{
    int digit;                          // Digit read from file
    int image[MAXROWS][MAXCOLS];        // Pixel data read from file
};

// Function Prototypes for functions included at the end of main.cpp
//void Print(const int image[MAXROWS][MAXCOLS]);
void Bars(int n);
void PrintCounters(int counters[ ]);
void PrintImage(const int image[MAXROWS][MAXCOLS]);

// Function Prototypes for the functions you must implement in project01.cpp
void GetNextImage(ifstream& datastream, int counters[], Record& data);
void Transpose(int image[MAXROWS][MAXCOLS]);
void FlipHorizontal(int image[MAXROWS][MAXCOLS]);
void FlipVertical(int image[MAXROWS][MAXCOLS]);
void RotateCW(int image[MAXROWS][MAXCOLS]);
void RotateCCW(int image[MAXROWS][MAXCOLS]);

// Start of main() function

int main (int argc, char * const argv[])      // Command-line arguments (more on this later)
{
  ifstream inputs;					    // Input file stream variable for test file
  char op, ch;							// Hold operation and optional char input from test file
  string  comment;                      // Holds comment string input from test file
  int counters[10];                     // Holds frequency of occurrence of each digit within data file
  string datafilename;                  // Name of image file
  ifstream datastream;                  // Image data stream
  int d;                                // Number read from input file
  Record r[LIMIT];                      // Record for temporary storage of tens lines of data from file
  Record temp;                          // Record for temporary storage of one line of data from file

  
  // Output usage message if test input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project01  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open test input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  Bars(2);

  // Process comment line from input file
  getline(inputs, comment);                          // Input file header comment
  cout << endl << comment << endl << endl;           // Output file header comment
	
  // Zero all counters
  for(int k = 0; k < 10; k++)
  {
    counters[k] = 0;
  }


  // Below is primary loop that processes each operation appearing within the test file.
  // Starts with an initial priming read of first operation
	
  inputs >> op;				                         // Attempt to input first test operation from file
	
  while (inputs)                                     // While Not-EOF
  {
    switch (op)                                      // Process operation input from test file
    {
	  case '#':   // Test file comment
			      getline(inputs, comment);          // Input the comment appearing in the test file
                  // cout << '#' << comment << endl;   // Do Not echo print comment
			      break;

	  case '[':   // Open specified data file for input
                  inputs >> datafilename;            // Input name of specified data file
                  datastream.open(datafilename.c_str());

                  cout << "open('" << datafilename << "'): ";

                  if (datastream)
                  {
                    cout << "done" << endl;
                  }
                  else
                  {
                    cout << "unable to open file" << endl;
                    cout << "Exiting program now..." << endl;
                    return 1;
                  };
			      break;

	  case ']':   // Close specified data file for input
                  datastream.close();
                  cout << "close('" << datafilename << "'): done" << endl;

                  // Zero all counters
                  for(int k = 0; k < 10; k++)
                  {
                    counters[k] = 0;
                  }
			      break;

	  case 'n':   // Read next line of image data from open data file
                  try
                  { 
                     cout << "GetNextImage: ";
                     GetNextImage(datastream, counters, temp);
                     cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
			      break;

	  case 'a':   // Read all remainings lines of image data from open data file
                  try
                  { 
                     cout << "GetAllImages: ";
                     GetNextImage(datastream, counters, temp);
                     while (datastream)
                     {
                        GetNextImage(datastream, counters, temp);
                     }
                     cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
			      break;

	  case 'c':   // Print histogram counters
                  cout << "PrintCounters: done" << endl;
                  PrintCounters(counters);   	 // Function definition appears at the end of this file
			      break;
			
      case 'h':   // Flip image horizontal
                  try
                  { 
                    cout << "FlipHorizontal: ";
                    FlipHorizontal(temp.image);
                    cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "Flip Vertical: Unknown error" << endl;
                  };
                  break;

      case 'v':   // Flip image vertical
                  try
                  { 
                    cout << "FlipVertical: ";
                    FlipVertical(temp.image);
                    cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
                  break;						
					  
      case 't':   // Transpose image across major diagonal
                  try
                  { 
                    cout << "Transpose: ";
                    Transpose(temp.image);
                    cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
                  break;

      case '+':   // Rotate 90 clockwise
                  try
                  { 
                    cout << "RotateCW: ";
                    RotateCW(temp.image);
                    cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
                  break;

      case '-':   // Rotate 90 counter clockwise
                  try
                  { 
                    cout << "RotateCCW: ";
                    RotateCCW(temp.image);
                    cout << "done" << endl;
                  }
                  catch (...)
                  {
                    cout << "unknown error" << endl;
                  };
                  break;
					  
      case 'p':   // Print Image
                  try
                  { 
                    cout << "PrintImage: done" << endl;
                    PrintImage(temp.image);
                  }
                  catch (...)
                  {
                    cout << "Print Image: Unknown error" << endl;
                  };
                  break;

      case 'b':   // Print Bars
                  inputs >> d;
			      Bars(d);                            // Function definition appears at the end of this file
			      break;	

	  default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				  return 1;
                  break;
    }
//    cout << endl;
	  
    inputs >> op;	                                 // Attempt to input next command
  }
 
  Bars(2);

  return 0;
}

/************** Implementation of Print() and Bars() functions ********************/

// DO NOT MODIFY THIS CODE

void PrintCounters(int counters[ ])
// PrintCounters(...) - outputs values of all counter variables to stdout
{
    for(int k = 0; k < 10; k++)
    {
        cout << k << "\t" << counters[k] << endl;
    }
}

void PrintImage(const int image[MAXROWS][MAXCOLS]) 
// Print() -- outputs image row-by-row in desired format substituting
// * for 1 and - for 0.
{
	for(int r=0; r < MAXROWS; r++)        // Loop to visit each row in image
	{
		for(int c=0; c < MAXCOLS; c++)    // Loop to output every element on current row
		{
			if (image[r][c] > 0)         // Output appropriate symbol
			{
				cout << '*';
			}
			else 
			{
				cout << '-';
			}
		}
		cout << endl;
	}
	
}  // End Print()

void Bars(int n)
// Bars(N) -- prints N horizontal rows of bars 
{
    for(int k = 0; k < n; k++)
    	cout << "#################################################################" << endl;
}  // End Bars()

/************** DO NOT DELETE *************/
// The preprocessor directive below will import the function definitions 
// from the file project01.cpp and place them at the end of this file creating an
// Expanded Source File which is forwarded to the compiler for compilation.

#include "project01.cpp"

/**************  End of main.cpp  ***************/


