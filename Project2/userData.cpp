#include "userData.h"

// Constructor
UserData::UserData(double t_initial, double t_deposit, double t_interest, int t_numYears) {
    m_initialAmount = t_initial;
    m_monthlyDeposit = t_deposit;
    m_annualInterest = t_interest / 100;
    m_numberOfYears = t_numYears;

    m_totalNoDeposits = 0;
    m_totalWithDeposits = 0;
}
// Getters - Functions that obtain the private variables from an instance of this class
double UserData::getInitialInvestment() { 
    return m_initialAmount; 
}
double UserData::getMonthlyDeposit() { 
    return m_monthlyDeposit; 
}
double UserData::getAnnualInterest() { 
    return m_annualInterest; 
}
int UserData::getNumberOfYears() { 
    return m_numberOfYears; 
}

// Sets the Initial Investment Amount that was input
void UserData::setInitialInvestment(double t_initial) {
    this->m_initialAmount = t_initial;
}
// Sets the monthly deposit amount that was input
void UserData::setMonthlyDeposit(double t_deposit) {
    this->m_monthlyDeposit = t_deposit;
}
// Sets the annual interest that was input
void UserData::setAnnualInterest(double t_interest) {
    this->m_annualInterest = t_interest / 100;
}
// Sets the number of Years that will go into compounding interest
void UserData::setNumberOfYears(int t_numYears) {
    this->m_numberOfYears = t_numYears;
}
// Sets the total balance with monthly deposits
void UserData::setTotalWithDeposits(double t_total) {
    this->m_totalWithDeposits = t_total;
}
// Sets the total balance with NO monthly deposits
void UserData::setTotalNoDeposits(double t_total) {
    this->m_totalNoDeposits = t_total;
}
