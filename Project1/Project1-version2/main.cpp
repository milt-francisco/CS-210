/*
  * Author: Milton Francisco
  * CS-210 Project 1 - Chada Tech Clock
  * Date: January 13, 2024
  *
  * References: Zybooks CS210 Ch.1-11; https://learn.microsoft.com/en-us/cpp/cpp/; Chada Tech's PDF;
  * StackOverflow mostly for IDE questions;
  * https://google.github.io/styleguide/cppguide.html ; https://www.geeksforgeeks.org/c-plus-plus/;
  *
  * There are specific comments in the interface displayClocks function that describe how requirements
  * differ between Sense and the Chada Tech PDF.
*/

#include "interface.h"

int main(void) {
    Interface interface;    //Create an Interface object for Main Logic and Menu Display
    interface.mainMenu();   //Call the main logic function
    return 0;
}