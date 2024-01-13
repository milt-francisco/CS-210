#pragma once
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "userData.h"

class Calculations {
public:
    //Function to find the yearly balances with monthly deposits and interest
    void balanceWithMonthlyDeposit(UserData&);

    //Function to find the yearly balances with interest but no monthly deposits
    void balanceNoMonthlyDeposit(UserData&);

    //Helper function to display year balances in a formatted table
    void printDetails(int, double, double);

private:
    //Variables for table styling
    int YEAR_COLUMN = 6;
    int BALANCE_COLUMN = 24;
    int INTEREST_COLUMN = 32;
};

#endif