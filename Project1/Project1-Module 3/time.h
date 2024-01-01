#pragma once
//See userInterface.h comment
#include "globals.h"

// Initialize constants for later changes if needed

// Getters
int getSecond();
int getMinute();
int getHour();

// Setters
void setSecond(int sec);
void setMinute(int min);
void setHour(int hr);

// Adders
void addOneHour();
void addOneMinute();
void addOneSecond();

