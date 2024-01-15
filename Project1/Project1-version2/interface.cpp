#include "interface.h"

//Constructor
Interface::Interface() {
    /*
    * This constructor initializes the contents of the MENU_SELECTIONS array.
    */
    MENU_SELECTIONS[0] = "Add One Hour";
    MENU_SELECTIONS[1] = "Add One Minute";
    MENU_SELECTIONS[2] = "Add One Second";
    MENU_SELECTIONS[3] = "Exit Program";
}

void Interface::mainMenu() {
    /*
    * This function holds the main logic of the program and houses the Time class that is manipulated by user input
    * as well as functions below.
    */   
    unsigned int hours;                   //Variable to hold the initial hour input
    unsigned int minutes;                 //Variable to hold the initial minute input
    unsigned int seconds;                 //Variable to hold the initial second input
    int userChoice;                       //Variable to hold user menu selection choice

    getUserTime(hours, minutes, seconds); //Obtain user's initial time input, passed by reference

    Time time(hours, minutes, seconds);   //Create a time object initialized to user's hour/minute/second input
    displayClocks(time);                  //Display clocks with user's initial input

    while (true) {                        //Loop until userChoice is 4 (getUserChoice will not return > 4 (in this case))
        printMenu(MENU_SELECTIONS, MENU_ITEMS, MENU_WIDTH); //Print user selection menu
        cout << "Enter your choice: ";                      //Ask user for input
        userChoice = getUserChoice(MENU_ITEMS);             //Input validation to ensure choice is < MENU_ITEMS (4 for now)

        system("CLS");                                      //Implemented a console clear to keep the console tidy.
        if (userChoice == 1) {                              //Adds an hour to time object and displays clocks
            time.addOneHour();
            displayClocks(time);

        }
        else if (userChoice == 2) {                       //Adds a minute to time object and displays clocks
            time.addOneMinute();
            displayClocks(time);

        }
        else if (userChoice == 3) {                       //Adds a second to time object and displays clocks
            time.addOneSecond();
            displayClocks(time);

        }
        else if (userChoice == 4) {                        //Exits program
            cout << "Exiting program." << endl;
            return;
        }
    }
}

void Interface::displayClocks(Time& time) {
    /*
    * This function displays a 12 and 24 hour clock side by side. The values displayed are obtained
    * from the time object that is passed in by reference.
    */
    unsigned int hr = time.getHour();       //Variable to hold updated hour
    unsigned int min = time.getMinute();    //Variable to hold updated minute
    unsigned int sec = time.getSecond();    //Variable to hold updated second

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

    cout << "*" << nCharString(6, ' ') << "12-Hour Clock" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-Hour Clock" << nCharString(6, ' ') << "*" << endl;
    // Sense grading tools wanted capitalized words in line 68 & 69, Chada Tech PDF did not.

    // cout << endl;  
    /*
    * The Sense grading tool utilizes an "endl" here.
    * BUT the Chada Tech PDF (for functional requirements) has pictures that indicate it is not wanted.
    * In the event we wanted the clock to have a vertical space in between, per Sense, uncommenting
    * the above line would solve the issue.
    */
    cout << "*" << nCharString(6, ' ') << formatTime12(hr, min, sec) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(hr, min, sec) << nCharString(9, ' ') << "*" << endl;

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

void Interface::printMenu(const string strings[], unsigned int numStrings, unsigned char width) {
    /*
    * This function prints the Menu that houses selections for the user. The selections are printed
    * by a loop to obtain the same format throughout the menu.
    */
    cout << nCharString(width, '*') << endl;

    for (unsigned int i = 0; i < numStrings; i++) {     //iterate through the menuSelections
        string start = "* " + to_string(i + 1) + " - " + strings[i];
        cout << start << nCharString(width - start.length() - 1, ' ') << "*" << endl;

        if (i < numStrings - 1) {   //If not at the last Menu item to print, add an additional endline.
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}

unsigned int Interface::getUserChoice(unsigned int maxChoice, bool isInitialTimeInput) {
    /*
    * This function returns a user choice, up to the maxChoice, and is used in (getUserTime and mainMenu).
    * This function is generalized by having a second argument that is set as a default to false.
    * This allows the function to also be utilized in obtaining the first user time inputs where the input
    * could possibly be 0 (occurs in getUserTime).
    */
    unsigned int userInput;           //Variable to hold user input

    do {
        cin >> userInput;

        if (userInput == 0 && isInitialTimeInput) {
            break;                        //If the value is 0 and it is the intial time input then it is allowed to exit loop
        }
    } while (userInput > maxChoice || userInput == 0); //Ensures input is < maxChoice and not Zero before exiting loop

    return userInput;
}

void Interface::getUserTime(unsigned int& hours, unsigned int& minutes, unsigned int& seconds) {
    /*
    * This function obtains a time from the user with values passed by reference from the mainMenu function.
    * This allows this function to update those variables for later use in initializing the Time object.
    * It utilizes subtle styling to enhance user experience, but could definitely be better.
    */
    cout << string(HEADER_SIZE, '*') << endl;
    cout << "* Welcome to Chada Tech's International Standard Clock! *" << endl;
    cout << string(HEADER_SIZE, '*') << endl;
    cout << "First, we will obtain a time of your choice." << endl << endl;

    cout << "Enter an hour (0-23): ";
    hours = getUserChoice(23, true);

    cout << endl << "Enter a minute (0-59): ";
    minutes = getUserChoice(59, true);

    cout << endl << "Enter a second (0-59): ";
    seconds = getUserChoice(59, true);
    system("CLS");                    // Implemented a clearscreen to keep the console tidy.
}


//String Manipulation Functions

string Interface::formatTime24(unsigned int hr, unsigned int min, unsigned int sec) {
    /*
    * This function creates and returns a 24-hour time string.
    */
    return twoDigitString(hr) + ":" + twoDigitString(min) + ":" + twoDigitString(sec);
}

string Interface::formatTime12(unsigned int hr, unsigned int min, unsigned int sec) {
    /*
    * This function creates and returns a 12-hour time string. It utilizes the 24-hour time
    * to determine if it is A.M. or P.M.
    */
    string suffix = " A M";                   //Variable that shows if it is A.M. or P.M.
    if (hr > 11) {
        suffix = " P M";
        hr = hr - 12;
    }
    (hr == 0) ? hr = 12 : hr;

    return twoDigitString(hr) + ":" + twoDigitString(min) + ":" + twoDigitString(sec) + suffix;
}

string Interface::twoDigitString(unsigned int n) {
    /*
    * This function takes an unsigned int argument and returns a 2 digit string.
    * If it is already 2 digits, it converts to a string and returns. Otherwise,
    * it adds a Zero in front of the digit and returns as a string.
    */
    string twoDigit;                //Variable to hold a generated string
    if (n < 10) {
        twoDigit.append("0");
    }
    twoDigit.append(to_string(n));  //Converts the argument to a string
    return twoDigit;
}

string Interface::nCharString(size_t n, char c) {
    /*
    * This function is, essentially, how the string fill constructor works.
    * It takes 2 arguments and returns a string of chars 'c', that is size 'n' length.
    */
    string charString(n, c);      //Variable to hold the generated string
    return charString;
}