#pragma once
#ifndef USER_DATA_H
#define USER_DATA_H

#include <cmath>
#include <iostream>
#include <iomanip>

// #include "userInterface.h"
using namespace std;

class UserData {
public:
    // Constructor
    UserData(double, double, double, int);

    // Getters 
    double getInitialInvestment();
    double getMonthlyDeposit();
    double getAnnualInterest();
    int getNumberOfYears();

    // Setters
    void setInitialInvestment(double);
    void setMonthlyDeposit(double);
    void setAnnualInterest(double);
    void setNumberOfYears(int);
    void setTotalWithDeposits(double);
    void setTotalNoDeposits(double);

private:
    // variables set by constructor
    double m_initialAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // variables set after initialization
    double m_totalWithDeposits;
    double m_totalNoDeposits;
};

#endif