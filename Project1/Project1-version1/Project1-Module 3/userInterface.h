#pragma once 
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
/*
	Utilized #pragma once in each .h file as well as the Header Guards shown.
	This is for specific compilers and protects against pragma failing. There is debate over which is best practice in current times. Good convention is why not both.

	Reference: https://learn.microsoft.com/en-us/cpp/preprocessor/once?view=msvc-170
	Reference: https://stackoverflow.com/questions/5776910/what-does-pragma-once-mean-in-c
*/

#include <iostream>
#include <stdlib.h>
#include "stringManip.h"
#include "time.h"
#include "globals.h"

// Generalized getUserChoice to utilize in getUserTime() and mainMenu()
unsigned int getUserChoice(unsigned int maxChoice, bool isInitialTimeInput = false);
/*
For getUserChoice function => I encountered a large issue during compilation because I was redefining the default parameter isInitialTimeInput in the function definition in userInterface.cpp
Fixed by no longer defining a default parameter in the function "definition" because its already defined in the function "declaration" above.
*/

// Displays 12 and 24 hour clocks side by side in console
void displayClocks(unsigned int h, unsigned int m, unsigned int s);

// Function for Menu Logic 
void mainMenu();

// Function that Prints Menu Options
void printMenu(const string strings[], unsigned int numStrings, unsigned char width);

// Retrieve User Input for Initial Time
void getUserTime();

#endif