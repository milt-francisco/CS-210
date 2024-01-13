#pragma once
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <cstdlib>
#include <memory>
#include <string>

#include "calculations.h"
#include "userData.h"

class UserInterface {
public:
    // Function displays collected user inputs
    void displayMenu(double& t_initial, double& t_deposit, double& t_interest, int& t_numYears);

    //Function displays the applicable report (table) header
    void displayReportHeader(int t_headerChoice = 0);

    //Function validates a user input and returns a double
    double getDouble(string message);
    
    //Function valdiates a user input and returns an int
    int getInt(string message);

    //Function creates a UserData object
    UserData getUserData();

private:
    //Constant Variables set to prevent magic numbers when formatting tables
    int YEAR_COLUMN = 6;
    int BALANCE_COLUMN = 24;
    int INTEREST_COLUMN = 32;
    int MENU_WIDTH = 64;
};
#endif