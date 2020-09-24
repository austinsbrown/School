#pragma once

#include <iostream>
using namespace std;

#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
    private:
    int millsec;
    int seconds;
    int mins;
    int hours;

    public:
    Clock();                                        // default constructor
    ~Clock();                                       // deconstructor
    void AddSec();                                  // add 1 second
    void AddMillSec();                              // add 1 millisecond
    void Reset();                                   // reset the clock
    void PrintSMH();
    void PrintMsSMH();
    void SetTime(int, int, int, int);
    
};

#endif
