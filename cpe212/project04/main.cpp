//
// main.cpp -- 2019 Spring -- Project04  Priority Queue
//
// Driver program for PriorityQ ADT -- The text files read by this code contain a series of commands
// that will help you test your PriorityQ ADT code by triggering various PriorityQ class methods.
//
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include <new>
#include <cstddef>
#include "priorityq.h"

using namespace std;

int main(int argc, char* argv[])
{
  ifstream inputs;					// Input file for commands
  char op;						    // Hold operation
  int n;                            // Integer input from file
  PriorityQ* ptr = NULL;		    // Will point to priority queue object
  Message msg;                      // Assembled message
  Priorities p;                     // Message priority
  char c;                           // Message priority input from file
  string s;                         // Message string from file
  int uid = 0;                      // Used to generate unique message identifier
  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project04  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Process commands from input file
  getline(inputs, s);              // Input comment line
  cout << s << endl;               // Echo comment line
  inputs >> op;				        // Attempt to input first command
  while (inputs)
  {
    switch (op)   // Identify and perform operation input from file
    {
      case '#':   // Echo Comment
                  getline(inputs, s);
                  cout << "--------\n" << op << s << endl;
                  break;

      case 'c':   // Constructor
                  cout << endl << "Constructor()";
                  try
                  {
                     ptr = new PriorityQ;
                     cout << endl;
                  }
                  catch ( std::bad_alloc )
                  {
                     cout << "Failed : Terminating now..." << endl;
                     return 1;
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure : Terminating now..." << endl;
                     return 1;
                  }
                  break;

      case '+':   // Enqueue
                  inputs >> c;                   // Input message priority from file
                  inputs.ignore(100, ' ');       // Skip one space
                  getline(inputs,s);             // Input rest of line as the message
                  cout << "Enqueue(" << c << " '" << s << "'" << ")";
                  try
                  {
                     switch (c)
                     {
						     case 'H':  msg.SetPriority(HIGH);    break;
						     case 'M':  msg.SetPriority(MEDIUM);  break;
						     case 'L':  msg.SetPriority(LOW);     break;
                     }
                     msg.SetMessage(s);
                     msg.SetUID(uid);
                     uid++;
                     ptr->Enqueue(msg);
                  }
                  catch (FullPQ)
                  {
                     cout << " -- Failed Full PriorityQ"; 
                  }
                  catch ( ... )
                  {
                     cout << " -- Unknown Failure";
                  }
                  cout << endl;
                  break;

      case '-':   // Dequeue
                  cout << "Dequeue() -- ";
                  try
                  {
                     ptr->Dequeue();
                     cout << "Successful";
                  }
                  catch (EmptyPQ)
                  {
                     cout << "Failed Empty PriorityQ";
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  cout << endl;
                  break;

      case 'x':   // Purge
                  inputs >> c;                   // Input message priority from file
                  cout << "Purge(" << c << ")";
                  try
                  {
                     switch (c)
                     {
						     case 'H':  ptr->Purge(HIGH);    break;
						     case 'M':  ptr->Purge(MEDIUM);  break;
						     case 'L':  ptr->Purge(LOW);     break;
                     }
                  }
                  catch (EmptyPQ)
                  {
                     cout << " -- Failed Empty PriorityQ"; 
                  }
                  catch ( ... )
                  {
                     cout << " -- Unknown Failure";
                  }
                  cout << endl;
                  break;

      case '?':   // Peek
                  inputs >> n;
                  cout << "Peek(" << n << ") -- ";
                  try
                  {
                     ptr->Peek(n).Print();
                  }
                  catch (InvalidPeekPQ)
                  {
                     cout << "Failed Invalid Peek PriorityQ";
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  cout << endl;
                  break;

      case 'u':   // IsPresent
                  inputs >> n;
                  cout << "IsPresent(" << n << ") -- ";
                  try
                  {
                     ptr->IsPresent(n).Print();
                  }
                  catch (InvalidUIDPQ)
                  {
                     cout << "Failed Invalid UID PriorityQ";
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  cout << endl;
                  break;


      case 'f':   // Front
                  cout << "Front() -- ";
                  try
                  {
					  ptr->Front().Print();
                  }
                  catch (EmptyPQ)
                  {
                     cout << "Failed Empty PriorityQ";
                  }
                  catch ( ... )
                  {
                     cout << " -- Unknown Failure";
                  }
                  cout << endl;
                  break;

      case 'r':   // Rear
                  cout << "Rear() -- ";
                  try
                  {
					 ptr->Rear().Print();
                  }
                  catch (EmptyPQ)
                  {
                     cout << "Failed Empty PriorityQ";
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  cout << endl;
                  break;
			
      case 'p':   // Print PriorityQ
                  cout << "Print() -- ";
                  try
                  {
                     ptr->Print();	
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  cout << endl;			  
                  break;	
		
      case 's':   // Size of PriorityQ
                  cout << "Size() -- "; 
                  try
                  {
                     cout << ptr->Size() << endl;  
                  }
                  catch ( ... )
                  {
                     cout << "Unknown Failure";
                  }
                  break;

      case 'm':   // Make PriorityQ Empty but ready for use
                  cout << "MakeEmpty()" << endl; 
                  try
                  {
                     ptr->MakeEmpty();
                  }
                  catch ( ... )
                  {
                     cout << " -- Unknown Failure";
                  }
                  break;			
			
      case 'd':   // Destructor
                  cout << "Destructor()" << endl << endl;
                  try
                  {
                     delete ptr;
                     ptr = NULL;
                  }
                  catch ( ... )
                  {
                     cout << " -- Unknown Failure";
                  }
                  break;

      default:    // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				  return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }
  
  return 0;
} // End main()

