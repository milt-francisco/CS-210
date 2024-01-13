/*
 * Milton Francisco
 * Project Two - Airgead Banking App
 * This program will calculate and display the compound interest of values obtained from user input.
 * This is used to show how monthly deposits can dramatically impact your balance over time.
 */
#include "userInterface.h"

int main(void) {
    char choice;                                        //Variable for continuing loop
    auto interface = make_unique<UserInterface>();      //Creates a new unique pointer for UserInterface Class

    while (true) {
        auto user = interface->getUserData();           //Obtains and displays input collected from user
        auto calculate = make_unique<Calculations>();   //Creates a new unique pointer for Calculations Class

        interface->displayReportHeader();               //Display applicable table header
        calculate->balanceNoMonthlyDeposit(user);       //Generates and displays balance & interest table
        interface->displayReportHeader(1);              //Display applicable table header
        calculate->balanceWithMonthlyDeposit(user);     //Generates and displays balance & interest table

        cout << "Try again? [Y/N]" << endl;
        cin >> choice;
        choice = toupper(choice);                       //Ensures input is case-insensitive
        if (choice != 'Y') {                            //Breaks loop and ends program if user input is anything other than y
            break;                                      //Simple validation to check that user wants to continue
        }
    }// while

    return 0;
}  // main