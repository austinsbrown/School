//
// main.cpp --  Project00, CPE212 Spring 2019 -- Practice Project
//
// Place the definitions for the missing functions into the file project00.cpp
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//

// List of allowed include files appear below
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;                    // Global using declaration


// Function Prototypes for the functions you must implement in project01.cpp
void PrintText(string& s);
void PrintStars(int n);


// Start of main() function

int main (int argc, char * const argv[])      // Command-line arguments (more on this later)
{
  ifstream inputs;					    // Input file stream variable for test file
  char op, ch;							// Hold operation and optional char input from test file
  string  comment;                      // Holds comment string input from test file
  string  operand;                      // Holds operand from input file
  int     num;                          // Hold number of stars read from input file

  
  // Output usage message if test input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project00  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open test input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Process comment line from input file
  getline(inputs, comment);                          // Input file header comment
  cout << endl << comment << endl << endl;           // Output file header comment
	
  // Below is primary loop that processes each operation appearing within the test file.
  // Starts with an initial priming read of first operation
	
  inputs >> op;				                         // Attempt to input first test operation from file
	
  while (inputs)                                     // While Not-EOF
  {
    switch (op)                                      // Process operation input from test file
    {
	  case '#':   // Test file comment
			      getline(inputs, comment);          // Input and echo the comment appearing in the test file
			      cout << '#' << comment << endl;
			      break;
			
	  case 't':   // Print Text
                  inputs.get(ch);                    // Consume and ignore space between op and operand
                  getline(inputs, operand);          // Input and echo the comment appearing in the test file
			      PrintText(operand);   	         // Place Missing Function Definition in project00.cpp
			      break;					
			
	  case '*':   // Print Bars
                  inputs >> num;
			      PrintStars(num);                   // Place Missing Function Definition in project00.cpp
			      break;				

	  default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				  return 1;
                  break;
    }
    cout << endl;
	  
    inputs >> op;	                                 // Attempt to input next command
  }
 
  
  return 0;
}

/************** DO NOT DELETE *************/
// The preprocessor directive below will import the function definitions 
// from the file project00.cpp and place them at the end of this file creating an
// Expanded Source File which is forwarded to the compiler for compilation.

#include "project00.cpp"

/**************  End of main.cpp  ***************/


