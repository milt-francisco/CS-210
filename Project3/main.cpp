/*
 * Author: Milton Francisco
 * CS210 - Project 3 - Corner Grocer
 * This program analyzes text records generated throughout the day by a grocery store. It records items purchased from the store, for a given day, into a map with key/value pairs.
 * It also has functionality to show all of the items purchased in normal form, as well as in histogram form.
 */
#include <cstdlib>
#include <iostream>
#include "inventory.h"
using namespace std;

void mainMenu(Inventory&);

int main(void) {
    Inventory inventory;                                        // Variable to create an inventory object
    string inputFile = "CS210_Project_Three_Input_File.txt";    // Variable to hold the input file
    try {                                                       // Attempt to read and distribute file contents to frequencyMap
        inventory.readInputFile(inputFile);                     // Reads and distributes file contents to inventory object
    }
    catch (exception& exc) {                                    // Closes program if error in reading and storing input file
        cout << exc.what() << endl;                             // Display issue to user
        return 1;                                               // Return non-zero exit code to indicate program failure
    }
    try {
        inventory.saveData();                                   // Created in the beginning of the program without user intervention and is for backup purposes
    }
    catch (exception& exc) {                                    // Alert user if failed to backup data
        cout << exc.what() << endl;
        return 2;                                               // Return non-zero exit code to indicate program failure
    }
    
    mainMenu(inventory);                                        // Display the Menu Interface

    return 0;
}//main


void mainMenu(Inventory& inventory) {
    int choice;             //Variable to hold user choice
    do {
        //Main Menu display
        cout << string(12, '*') << " Main Menu " << string(12, '*') << endl;
        cout << "Choose from the following options:" << endl;
        cout << "1 - Find Item Frequency" << endl;
        cout << "2 - Display Complete Inventory" << endl;
        cout << "3 - Display Histogram of Complete Inventory" << endl;
        cout << "4 - Exit Program" << endl;
        cout << "Enter your choice [1-4]: ";

        cin >> choice;      // Get user input

        switch (choice) {   // Determine what user input is
        case 1:             // Menu Option 1 - Find specific item with amount
            inventory.findItemFrequency();
            break;
        case 2:             // Menu Option 2 - Display Complete Item Inventory
            inventory.printAllItemFrequencies();
            break;
        case 3:             // Menu Option 3 - Display Histogram of Complete Inventory
            inventory.printAllItemHistogram();
            break;
        case 4:             // Menu Option 4 - End Program
            cout << "Exiting program." << endl;
            break;
        default:            // Input Validation for anything outside of the range 1 to 4 or Not a number
            system("CLS");  // Clear console
            cout << "Invalid Choice! Please enter a number [1-4]" << endl << endl; //Extra endline for style/readability
            cin.clear();                                                           //Clear input stream
            cin.ignore(1000, '\n');                                                //Ignore input text until newline
        }
    } while (choice != 4);
}//mainMenu