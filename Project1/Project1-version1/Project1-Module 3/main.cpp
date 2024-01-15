/*
    Author: Milton Francisco
    CS-210 Project 1 - Chada Tech Clock
    Date: January 1st, 2023
    References: Zybooks CS210 Ch.1-5; https://learn.microsoft.com/en-us/cpp/cpp/; Chada Tech's PDF; StackOverflow mostly for IDE questions;
    https://google.github.io/styleguide/cppguide.html ; https://www.geeksforgeeks.org/c-plus-plus/; 

    Majority of comments are in the .h files with specific problems/bug fixes in .cpp files.
    userInterface.cpp comments discuss contradictory requirements between Sense and Chada Tech PDF.
*/

#include "userInterface.h"

int main(void) {

    getUserTime();
    mainMenu();

    return 0;
}
