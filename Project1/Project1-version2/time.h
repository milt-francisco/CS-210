#pragma once
#ifndef TIME_H
#define TIME_H

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Time {
public:
    //Constructor
    Time(unsigned int&, unsigned int&, unsigned int&);

    // Getters
    unsigned int getSecond();
    unsigned int getMinute();
    unsigned int getHour();

    // Setters
    void setSecond(int);
    void setMinute(int);
    void setHour(int);

    // Adders
    void addOneHour();
    void addOneMinute();
    void addOneSecond();

private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};
#endif