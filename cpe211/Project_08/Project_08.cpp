// ****************************************
// Program File: Cpp_header.cpp
//Name: Austin
//Course Section: CPE-211-01
// Lab Section: 4
// Due Date:
// program description:
// What the program does.
// ****************************************

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void menu() // prints the menu
{
	cout << "\n**********  Compression Menu  **********" << endl
	<< "0. Exit Program" << endl
	<< "1. Compress File" << endl
	<< "2. Uncompress File" << endl
	<< "****************************************" << endl;
}

string obtainInt() // gets an integer and returns it
{
	string num;
	cout << "\nInput your selection now: ";
	cin >> num;
	cin.ignore(INT_MAX, '\n');
	cout << num << endl << endl;
	return num;
}

bool openInputFile(ifstream &inputStream)
{
	string input; // input file name
	cout << "Enter the name of the input file: ";
	cin >> input;
	cout << input << endl << endl;

	inputStream.open(input.c_str()); // open file

	if(inputStream.fail())
	{
		cout << "*************** File Open Error ***************" << endl
		<< "==> Input file failed to open properly!!" << endl
		<< "==> Attempted to open file: " << input << endl
		<< "==> Selected operation has been canceled" << endl
		<< "***********************************************" << endl;
		return false;
	}	

	else
	{
		return true;
	}
}

void openOutputFile(ofstream &outputstream)
{
	string output;
	cout << "Enter the name of the output file: ";
	cin >> output;
	cout << output << endl;

	outputstream.open(output.c_str());
}

void compress(ifstream &inputstream, ofstream &outputstream) // function that compress files
{
	char firstchar;
	char secondchar;
	int num = 1;

	inputstream >> firstchar; // priming read
	if(! inputstream.good())
	{
		cout << "\n*************** Empty Input File **************" << endl
		<< "==> Empty file for Compression" << endl
		<< "==> Nothing written to the output file" << endl
		<< "***********************************************" << endl;
		return;
	}

	while(inputstream.get(secondchar))
	{
		if(firstchar == secondchar)
		{
			num++;
		}

		else
		{
			outputstream << num << firstchar;
			firstchar = secondchar;
			num = 1;
		}
	}

	outputstream << "1" << endl;

	inputstream.close();
	outputstream.close();

	cout << "\n==> File has been Compressed" << endl;
}

void decompress(ifstream &inputstream, ofstream &outputstream) // decompresses files
{
	int decNum;
	char decChar;
	
	inputstream >> decNum; // priming read
	if(! inputstream.good()) // empty file message
	{
		cout << "\n*************** Empty Input File **************" << endl
		<< "==> Empty file for Decompression" << endl
		<< "==> Nothing written to the output file" << endl
		<< "***********************************************" << endl; 
		return;
	}

	else
	{
		while(inputstream.good())
		{
			inputstream.get(decChar);
			for(int i = 0; i < decNum; i++)
			{
				outputstream << decChar;
			}

			inputstream >> decNum;
		}
		cout << "\n==> File has been Decompressed" << endl;
	}

	inputstream.close();
	outputstream.close();
	
}

int main() 
{
	while(0==0)
	{
		ifstream infile; // in file stream
		ofstream outfile; // out file stream

		menu(); // print the main menu
		
		bool correctNum = false; // ask user what to do
		string optionNum;
		bool fileOpen = false;

		while(correctNum == false)
		{
			optionNum = obtainInt();
			if((optionNum == "0" || optionNum == "1" || optionNum == "2") && optionNum.length() == 1)
			{
					correctNum = true;
			}

			else
			{
				cout << "************** Invalid Selection **************" << endl
				<< "==> Invalid character entered!!" << endl
				<< "==> Please enter 0, 1 or 2" << endl
				<< "***********************************************" << endl;

				menu();
			}
		}

		if(optionNum == "0")
		{	
			cout << "Quit selected.  Terminating program now...\n" << endl;
			break;
		}

		fileOpen = openInputFile(infile);
		if(fileOpen == false)
		{
			continue;
		}	

		openOutputFile(outfile);
		
		if(optionNum == "1")
		{
			compress(infile, outfile);
		}
		else if(optionNum == "2")
		{
			decompress(infile, outfile);
		}
	}	
	
	return 0;
}
