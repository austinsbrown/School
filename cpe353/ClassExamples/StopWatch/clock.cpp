#include "clock.h"

Clock::Clock()
{
    seconds = 0;
    minutes = 0;
    hours = 0;

}


int Clock::hrs()
{
    return hours;
}


int Clock::mins()
{
    return minutes;
}


int Clock::secs()
{
    return seconds;
}


void Clock::addSecond()
{
    seconds++;

    if(seconds == 60)
    {
        seconds = 0;
        minutes++;
    }

    if(minutes == 60)
    {
        minutes = 0;
        hours++;
    }
}


void Clock::reset()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}
