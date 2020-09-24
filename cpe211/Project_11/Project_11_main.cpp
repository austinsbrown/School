// *************************************************************
// main function declaration to run the class funcitons
// DO NOT MODIFY THIS FILE
// **************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P11.h" 

using namespace std;

int main()
{
    cout << endl << string(40,'*') << endl;
    cout << "Number Format:   11/15/2017\n";
    cout << "Name Format: November 15, 2017\n";

    // construct two objects of the class - one using 
    // default date the other using paramertized constructor
    //
    cout << string(40,'*') << endl << endl;
    cout << "Constructor Test\n";
    cout << "----------------\n";
    cout << "      Default Constructor\n";
    Date date1;
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl;

    cout << "      Parameterized Constructor\n";
    Date date2(6,20,1970);
    date2.WriteNumberFormat();
    date2.WriteNameFormat();
    cout << string(40,'*') << endl << endl;
    
    // verifying set date function
    cout << string(40,'*') << endl;
    cout << "Set Date Test\n";
    cout << "-------------\n";
    date1.SetDate(10,6,2000);
    date1.WriteNumberFormat();
    date1.WriteNameFormat();
    cout << string(40,'*') << endl << endl;
    
    // verifying same date function
    cout << string(40,'*') << endl;
    cout << "Same Date Test\n";
    cout << "-------------\n";
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Same Date?: " << boolalpha <<  date1.SameDate(date2) << endl << endl;

    date2.SetDate(10,6,2000);
    cout << "Date1: ";
    date1.WriteNumberFormat();
    cout << "Date2: ";
    date2.WriteNumberFormat();
    cout << "Same Date?: " << boolalpha <<  date1.SameDate(date2) << endl;
    cout << string(40,'*') << endl << endl;


    cout << string(40,'*') << endl;
    cout << "Testing every month for correct output\n";
    cout << "--------------------------------------\n";
    
    //cout << string(40,'*') << endl;
    for (int i = 1; i<=12; i++)
    {
        date1.SetDate(i,i,2018);
        date1.WriteNumberFormat();
        date1.WriteNameFormat();
        cout << string(40,'*') << endl;
    }
}
