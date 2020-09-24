// ****************************************
// Program File: Cpp_header.cpp
//Name: Austin Brown
//Course Section: CPE-211-01
// Lab Section: 4
// Due Date:9/28/18
// program description: reads names and scores from a text file
// and calculates averages
// ****************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << endl;
		cout << "Incorrect number of command line arguments provided." << endl
		<< "This program requires 2 command line arguments:" << endl
		<< "An input filename and an output filename" << endl << endl
		<< "Program usage is:" << endl
		<< "./Project_06 InputFileName OutputFileName" << endl << endl;
	}
	
	ifstream infile;
	ofstream outfile;

	string input, output; // input and output strings
	input = argv[1];
	output = argv[2];

	cout << endl;
	
	infile.open(input.c_str());
	
	cout << "Opening Input File: " << input << '\n' << endl;
	
	
	outfile.open(output.c_str());
	if(! outfile.fail())
	{
		cout << "Opening Output File: " << output << '\n' << endl;
	}
	infile.open(input.c_str());
	
	bool test = false;
	
	while(test == false)
	{
		infile.close();
		infile.clear();
		infile.open(input.c_str()); // attempt to open file

		if(! infile.fail())
		{
			test = true;
		}

		else
		{
			cout << "*************** File Open Error ***************" << endl;
			cout << "==> Input file failed to open properly!!" << endl;
			cout << "==> Attempted to open file: " << input << endl;
			cout << "==> Please try again..." << endl;
			cout << "***********************************************" << endl;
			cout << endl;
			cout << "Enter the name of the input file: ";
			cin >> input;
			cout << endl;
		}
	}

	test = false;

	while(test == false)
	{
		outfile.close();
		outfile.clear();
		outfile.open(output.c_str()); // attempt to open file

		if(! outfile.fail())
		{
			test = true;
		}

		else
		{
			cout << "*************** File Open Error ***************" << endl;
			cout << "==> Output file failed to open properly!!" << endl;
			cout << "==> Attempted to open file: " << output << endl;
			cout << "==> Please try again..." << endl;
			cout << "***********************************************" << endl;
			cout << endl;
			cout << "Enter the name of the output file: ";
			cin >> output;
			cout << endl;

		}
	}	

	int quizNum, homeworkNum, examNum; // number of quizzes, homework, and exams
	infile >> quizNum >> homeworkNum >> examNum; // extract quiz, homeowrk, and exam numbers

	outfile << left;

	string lastName, firstName;
	int keyQuizPoints = 0;
	int keyHomeworkPoints = 0;
	int keyExamPoints = 0;
	int currentPoint;


	infile >> lastName >> firstName;

	if(! infile.good()) // test for empty file
	{
		cout << "************* Input File Is Empty *************" << endl
		<< "==> The input file is empty." << endl
		<< "==> Terminating the program." << endl
		<< "***********************************************" << '\n' << endl;
		
		outfile << "Input file " << input << " is empty." << endl;
	}
	else
	{ 
		outfile << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First" << setw(6) <<
		"Quiz" << setw(6) << "HW" << setw(6) << "Exam" << setw(7) << "Total" << setw(9) <<
		"Average" << endl;

		outfile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" // write headings
		<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
		<< setw(7) << "-----" << setw(9) << "-------" << endl;

		for(int i = 0; i < quizNum; i++) // get quiz info
		{
			infile >> currentPoint;
			keyQuizPoints = keyQuizPoints + currentPoint;
		}

		currentPoint = 0;
		for(int i = 0; i < homeworkNum; i++) // get quiz info
		{
			infile >> currentPoint;
			keyHomeworkPoints = keyHomeworkPoints + currentPoint;
		}

		currentPoint = 0;
		for(int i = 0; i < examNum; i++) // get quiz info
		{
			infile >> currentPoint;
			keyExamPoints = keyExamPoints + currentPoint;
		}

		int keyTotal = keyExamPoints + keyHomeworkPoints + keyQuizPoints; // total points

		outfile << setw(3) << " " << setw(12) << lastName.substr(0,10) << setw(7) << // output info
		firstName.substr(0,5) << setw(6) << keyQuizPoints << setw(6) <<
		keyHomeworkPoints << setw(6) << keyExamPoints << setw(7) << keyTotal << setw(9)
		 << "100.00" << endl;

		outfile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" // write headings
		<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
		<< setw(7) << "-----" << setw(9) << "-------" << endl;

		int quizPoints = 0; // actual scores for each person
		int homeworkPoints = 0;
		int examPoints = 0;
		int total = 0;
		int num = 1; // number that goes beside each name
		int classTotal = 0;

		infile >> lastName; // priming read for while loop
		
		bool noStudent = false;
		if (infile.eof())
		{
			noStudent = true;
		}
		
		while(! infile.eof())
		{
			infile >> firstName; // get first and last name;

			currentPoint = 0;
			quizPoints = 0;
			for(int i = 0; i < quizNum; i++) // get quiz info
			{
				infile >> currentPoint;
				quizPoints = quizPoints + currentPoint;
			}

			currentPoint = 0;
			homeworkPoints = 0;
			for(int i = 0; i < homeworkNum; i++) // get quiz info
			{
				infile >> currentPoint;
				homeworkPoints = homeworkPoints + currentPoint;
			}

			currentPoint = 0;
			examPoints = 0;
			for(int i = 0; i < examNum; i++) // get quiz info
			{
				infile >> currentPoint;
				examPoints = examPoints + currentPoint;
			}

			total = examPoints + homeworkPoints + quizPoints; // total points
			float average;
			average = (float(total) / float(keyTotal)) * 100;

			outfile << fixed << setprecision(2); // format output

			outfile << setw(3) << num << setw(12) << lastName.substr(0,10) << setw(7) << // output info
			firstName.substr(0,5) << setw(6) << quizPoints << setw(6) <<
			homeworkPoints << setw(6) << examPoints << setw(7) << total << setw(9)
			 << average << endl;

			 num++; // adds one to num
			 
			 infile >> lastName;
			 
			 classTotal = total + classTotal;
		 	}
		
		if(noStudent == false)
		{
			outfile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----" // write headings
			<< setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
			<< setw(7) << "-----" << setw(9) << "-------" << endl;
		
			int maxTotal;
			maxTotal = keyTotal * (num - 1);
			float classAverage = (float(classTotal) / float(maxTotal)) * 100;
		
			outfile << endl;
			outfile << "Class Average = " << classAverage << endl;
		}
		else
		{
			cout << "Input file did not contain any students" << endl; 
			outfile << "Input file did not contain any students" << endl;
		}
	}

	infile.close();
	outfile.close();
	return 0;
}
