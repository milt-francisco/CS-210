#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "time.h"
using namespace std;

class Interface {
public:
    //Constructor
    Interface();

    //Main menu Logic
    void mainMenu();

    //Displays 12 and 24 hour clocks side by side
    void displayClocks(Time&);

    //Displays the user selection menu
    void printMenu(const string strings[], unsigned int, unsigned char);

    //Gets user choice up to a specified limit
    unsigned int getUserChoice(unsigned int, bool isInitialTimeInput = false);

    //Gets initial time from user
    void getUserTime(unsigned int&, unsigned int&, unsigned int&);

    // Receives a number and returns a two digit string of that number (ex. 9 -> "09", 12 -> "12")
    string twoDigitString(unsigned int);

    // Fills string, with char c, to size n, using string fill constructor.
    string nCharString(size_t, char);

    // Formats hour, minute, second in user-friendly 24 hr time string
    string formatTime24(unsigned int, unsigned int, unsigned int);

    // Formats hour, minute, second in user-friendly 12 hr time string
    string formatTime12(unsigned int, unsigned int, unsigned int);

private:
    const unsigned int MENU_ITEMS = 4;  //Variable used to iterate over amount of menu items
    string MENU_SELECTIONS[4];          //Array to hold menu selections
    const unsigned int MENU_WIDTH = 26; //Variable to utilize in styling the menu
    int HEADER_SIZE = 58;               //Variable utilized in formatting the first Header styling
};

#endif