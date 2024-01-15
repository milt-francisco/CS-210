#include "time.h"
/*
  Getter, Setter & Adder functions for time
*/

int getSecond() {
    return seconds;
}
int getMinute() {
    return minutes;
}
int getHour() {
    return hours;
}

void setSecond(int sec) {
    seconds = sec;
}
void setMinute(int min) {
    minutes = min;
}
void setHour(int hr) {
    hours = hr;
}

void addOneHour() {
    int hr = getHour();

    if (hr < 23) {
        setHour(++hr);
        return;
    }

    setHour(0);
}
void addOneMinute() {
    int min = getMinute();
    if (min < 59) {
        setMinute(++min);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}
void addOneSecond() {
    int sec = getSecond();
    if (sec < 59) {
        setSecond(++sec);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}