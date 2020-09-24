#include "clock.h"

Clock::Clock()
{
    millsec = 0;
    seconds = 0;
    mins = 0;
    hours = 0;
}


Clock::~Clock()
{

}


void Clock::AddSec()
{
    seconds++;
    
    if(seconds == 60)
    {
        seconds = 0;
        mins++;
    }
    
    if(mins == 60)
    {
        mins = 0;
        hours++;
    }
}


void Clock::AddMillSec()
{
    millsec++;
    
    if(millsec == 1000)
    {
        millsec = 0;
        seconds++;
    }
    
    if(seconds == 60)
    {
        seconds = 0;
        mins++;
    }
    
    if(mins == 60)
    {
        mins = 0;
        hours++;
    }
}


void Clock::Reset()
{
    millsec = 0;
    seconds = 0;
    mins = 0;
    hours = 0;
}


void Clock::PrintSMH()
{
    cout << hours << ":" << mins << ":" << seconds << endl;
}


void Clock::PrintMsSMH()
{
    
}


void Clock::SetTime(int mi, int s, int m, int h)
{
    millsec = mi;
    seconds = s;
    mins = m;
    hours = h;
}





















