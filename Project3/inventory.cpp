#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "inventory.h"

void Inventory::readInputFile(const string& fileName) {
    /*
    * This function opens an input file, iterates through the input file,
    * and logs the contents of the file into a map with key/value pairs
    * of a <string, int>. The int is initialized to 1 if it is newly created,
    * otherwise it adds one to the applicable item's value.
    */
    ifstream input;                                       //Initialize input file handle
    string item;                                          //Variable to hold a string from the input file

    input.open(fileName);                                 //Open input file
    if (!input.is_open()) {                               //Check if input file opened successfully 
        throw runtime_error("Could not open input file"); //Alert user the input file was not opened
    }
    input >> item;                                          //Receive the first item from the input file.
    while (!input.fail()) {
        if (frequencyMap.count(item)) {                     //Checks if the entry exists in frequencyMap
            frequencyMap.at(item) = ++frequencyMap.at(item);//Adds one to the item's count;
        }
        else {                                              //If the entry does not exist, creates a new pair for frequencyMap
            frequencyMap.emplace(item, 1);
        }
        input >> item;                                      //Receive next item from input file
    }

    if (!input.eof()) {                                     //Check if file was completely read
        input.close();                                      //Close input file
        throw runtime_error("Input failure before reaching end of file."); //Alert user that file was not completely read and exit function
    }
    input.close();                                          // If successfully read, close input file
};

void Inventory::findItemFrequency() {
    /*
    * This function checks if an item, input by the user, is in the frequencyMap. It then displays
    * how many times the input item was found in the frequencyMap.
    */
    cout << endl;                                   //Extra endline for style/readability
    string item;                                    //Variable to receive input item from user

    cout << "Enter an item to search for: ";        //Prompt user to input an item
    cin >> item;                                    //Obtain user input
    cout << endl;                                   //Extra endline for style/readability
    if (frequencyMap.count(item)) {
        cout << item << " " << frequencyMap.at(item) << endl << endl; //Display if item found in frequency map extra endl for style/readability in console
    }
    else {
        cout << item << " was not found!" << endl << endl;  //Alert user that item is not in frequencyMap
    }
    system("pause");                                //Pause system flow so user can read the results
    system("CLS");                                  //Update console to remove previous output data
};

void Inventory::printAllItemFrequencies() {
    /*
    * This function prints the entire frequencyMap's contents including the item name
    * and how many times the item was logged.
    */
    cout << endl;                                           //Style/formatting table
    cout << setw(COLUMN_SIZE) << left << "Item" << "| Amount" << endl; 
    cout << string((COLUMN_SIZE * 2), '=') << endl;

    for (auto& pair : frequencyMap) {                       //Iterate through frequencyMap pairs
        cout << setw(COLUMN_SIZE) << left << pair.first << "| " << pair.second << endl;   //Display frequencyMap pair contents
    }
    cout << endl;
    system("pause");                                        //Pause system flow so user can read output
    system("CLS");                                          //Clear console to prepare for menu output
};

void Inventory::printAllItemHistogram() {
    /*
    * This function prints the entire frequencyMap's contents but displays the value
    * of the item's logged in a histogram-like format.
    */
    cout << endl;                                                                                   //Extra line for style/formatting
    for (auto& pair : frequencyMap) {                                                               //Iterate through frequencyMap pairs
        cout << setw(COLUMN_SIZE) << left << pair.first << "|" << string(pair.second, '*') << endl;   //Display frequencyMap pair contents by way of histogram
    }
    cout << endl;                                                                                   //Extra endline for style/readability
    system("pause");                                                                                //Pause system flow so user can read output
    system("CLS");                                                                                  //Clear console to prepare for menu output
};

void Inventory::saveData() {
    /*
    * This function saves the data, in the Class's private variable frequencyMap,
    * to an output file "frequency.dat"
    */
    ofstream output;                        //create output file handle
    output.open("frequency.dat");           //open output file

    if (!output.is_open()) {                //Handle error if output file cannot be opened
        throw runtime_error("Could not open output file: \"frequency.dat\"."); //throw error and return
    }
    for (auto& pair : frequencyMap) {       //Iterate through the frequencyMap
        output << pair.first << " " << pair.second << endl; //Output pair key and value
    }
    output.close();                         //Close output file
};