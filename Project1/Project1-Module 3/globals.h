#pragma once
//See userInterface.h comment
#ifndef GLOBALS_H
#define GLOBALS_H

#include "stringManip.h"

// Initialize constant variables in one place for future upgrades if desired
const unsigned int MENU_ITEMS = 4;
const string MENU_SELECTIONS[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
const unsigned int MENU_WIDTH = 26;

/*
    Encountered quite a bit of trouble with the below variables during compilation and had to try a lot of different things to develop a correct solution.
    I realize I could have put everything in main.cpp but for the sake of learning and trying new things I wanted to attempt modularization.

    Any and all feedback is greatly appreciated! Thank you for taking the time to read this far!
*/

// Initialize global variables as "extern" to indicate they are something during compilation and will be defined in a later file (globals.cpp).
extern unsigned int hours;
extern unsigned int minutes;
extern unsigned int seconds;

#endif