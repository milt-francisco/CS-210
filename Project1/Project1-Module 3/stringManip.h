#pragma once
//See userInterface.h comment
#ifndef STRING_MANIP_H
#define STRING_MANIP_H

#include <string>

using namespace std; // state here so it can be included and used in other files

/*
  String Manipulation Functions
*/

// Receives a number and returns a two digit string of that number (ex. 9 -> "09", 12 -> "12")
string twoDigitString(unsigned int n);
// Fills string, with char c, to size n, using string fill constructor.
string nCharString(size_t n, char c);
// Formats hour, minute, second in user-friendly 24 hr time string
string formatTime24(unsigned int h, unsigned int m, unsigned int s);
// Formats hour, minute, second in user-friendly 12 hr time string 
string formatTime12(unsigned int h, unsigned int m, unsigned int s);

#endif