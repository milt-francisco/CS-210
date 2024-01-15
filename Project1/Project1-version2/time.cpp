#include "time.h"

// Constructor
Time::Time(unsigned int& hours, unsigned int& minutes, unsigned int& seconds) {
    /*
    * Initializes a time object's hours, minutes and seconds. A Time object holds the
    * times as a 24-hour style time.
    */
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

//Getters - These functions return the applicable private time value.
unsigned int Time::getSecond() {
    return this->seconds;
}
unsigned int Time::getMinute() {
    return this->minutes;
}
unsigned int Time::getHour() {
    return this->hours;
}

//Setters - These functions set the applicable time value to the argument that is passed in.
void Time::setSecond(int seconds) {
    this->seconds = seconds;
}
void Time::setMinute(int minutes) {
    this->minutes = minutes;
}
void Time::setHour(int hours) {
    this->hours = hours;
}


//Update functions
void Time::addOneHour() {
    /*
    * This function adds one to the hour variable and if over 23 it resets the hour back to 0.
    */
    if (hours < 23) {
        setHour(++hours);
        return;
    }
    setHour(0);
}
void Time::addOneMinute() {
    /*
    * This function adds one to the minute variable and if over 59 it resets minute back to 0.
    */
    if (minutes < 59) {
        setMinute(++minutes);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}
void Time::addOneSecond() {
    /*
    * This function adds one to the second variable and if over 59 resets second back to 0.
    */
    if (seconds < 59) {
        setSecond(++seconds);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}