#ifndef CLOCK_H
#define CLOCK_H


class Clock
{
private:
    int seconds;
    int minutes;
    int hours;

public:
    Clock();
    int secs();
    int mins();
    int hrs();
    void addSecond();
    void reset();
};

#endif // CLOCK_H
