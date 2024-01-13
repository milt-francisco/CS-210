#include "userInterface.h"

void UserInterface::displayReportHeader(int t_headerChoice) {
    /*
     * This function establishes the header for the applicable Balance and Interest Reports.
     * t_headerChoice has a default of 0. This allows the use of this function for multiple reports.
     */
    if (t_headerChoice == 0) {
        cout << string(4, ' ') << "Balance and Interest Without Additional Monthly Deposits" << endl;
    }
    else {
        cout << string(5, ' ') << "Balance and Interest With Additional Monthly Deposits" << endl;
    }
    cout << string(MENU_WIDTH, '=') << endl;
    cout << setw(YEAR_COLUMN) << right << "Year";
    cout << setw(BALANCE_COLUMN) << right << "Year End Balance";
    cout << setw(INTEREST_COLUMN) << right << "Year End Earned Interest" << endl;
    cout << string(MENU_WIDTH, '-') << endl;
}//displayReportHeader

UserData UserInterface::getUserData() {
    /*
     * This function obtains the user input and returns a class initialized with obtained input.
     * This is essentially the Welcome Page for the program, and obtains initial user data.
     */
    system("CLS");
    double initialAmount = 0;                   //Variable to hold the initial input amount
    double monthlyDeposit = 0;                  //Variable to hold the initial monthly deposit
    double interest = 0;                        //Variable to hold the initial interest rate
    int years = 0;                              //Variable to hold the initial year amount

    //Menu Display
    cout << string(MENU_WIDTH, '#') << endl;
    cout << string(14, ' ') << "Welcome to the Airgead Banking App!" << endl;
    cout << string(MENU_WIDTH, '#') << endl;
    cout << string(10, '*') << " Data Input " << string(12, '*') << endl;

    try { //obtain user data
        initialAmount = getDouble("Enter Intial Investment Amount: ");
        monthlyDeposit = getDouble("Enter Monthly Deposit: ");
        interest = getDouble("Enter Annual Interest: ");
        years = getInt("Enter Number Of Years: ");
    }
    catch (exception& excep) {
        cout << excep.what() << endl;
        cout << "Error occured in getUserData" << endl;
    }
    system("CLS");      //Clear the windows console

    displayMenu(initialAmount, monthlyDeposit, interest, years);
    system("pause");    //Pause to allow user to observe their input
    cout << endl;       //Added for style/readability
   
    UserData user(initialAmount, monthlyDeposit, interest, years);  //Constructs new user class
   
    return user;
}//getUserData

double UserInterface::getDouble(string message) {
    /*
     * This function validates the user input ensuring no characters are input as well as
     * ensuring the input is in the correct range (Greater than 0). Returns a double.
     */
    cout << message;
    double input;                                               //Variable holds the value to be validated

    while (true) { 
        cin >> input;
        if (cin.fail()) {                                       //If input is not a double, reset instream and re-iterate through loop
            cout << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input: Enter a number" << endl;
            continue;
        }
        if (input > 0) {                                        //Acceptable input
            cout << endl;
            return input;
        }
        else {
            cout << "Invalid input: Enter a number > 0" << endl;//Must input > 0 for functional reqs
        }
    }
}//getDouble

int UserInterface::getInt(string message) {
    /*
     * This function validates the user input ensuring no characters are input as well as
     * ensuring the input is in the correct range (Greater than 0). Returns an int.
     */
    cout << message;
    int input;                                                  //Variable holds the value to be validated
    while (true) {
        cin >> input;
        if (cin.fail()) {                                       //If input is not an int, reset instream and re-iterate through loop
            cout << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input: Enter a number" << endl;
            continue;
        }
        if (input > 0) {                                        //Acceptable input
            cout << endl;
            return input;
        }
        else {
            cout << "Invalid input: Enter a number > 0" << endl;
        }
    }
}//getInput

void UserInterface::displayMenu(double& t_initial, double& t_deposit, double& t_interest, int& t_numYears) {
    /*
     * This function displays the "data input menu" after collecting the user's input
     */
    cout << string(MENU_WIDTH, '#') << endl;
    cout << "#" << string(21, ' ') << "Airgead Banking App" << string(22, ' ') << "#" << endl;
    cout << string(MENU_WIDTH, '#') << endl;
    cout << string(10, '*') << " Data Input " << string(12, '*') << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << t_initial << endl;
    cout << "Monthly Deposit: $" << t_deposit << endl;
    cout << "Annual Interest: " << t_interest << "%" << endl;
    cout << "Number Of Years: " << t_numYears << endl;
}