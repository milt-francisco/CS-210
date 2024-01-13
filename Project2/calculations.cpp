#include "calculations.h"

void Calculations::balanceNoMonthlyDeposit(UserData& t_user) {
    /*
     * This function finds the balance & interest earned every year and displays
     * the values to the console.
    */
    double runningBalance = t_user.getInitialInvestment();              //Variable holds initial investment from the UserData object passed in by reference
    double interest = t_user.getAnnualInterest();                       //Variable holds the annual interest rate from the passed in UserData object
    int numberOfYears = t_user.getNumberOfYears();                      //Variable holds the number of years from the passed in UserData object
    double yearEndBalance;                                              //Variable is used to hold the calculated year end balance
    double interestEarned;                                              //Variable is used to hold the interest found from yearEndBalnce - runningBalance
    const int MONTHS = 12;                                              //Variable to hold the constant of months in a year
    int year = 1;                                                       //Variable to hold the current year
    /*
    * Compound Interest Equation
    * A = P(1 + i/n)^nt
    */
    while (year <= numberOfYears) {
        yearEndBalance = runningBalance * pow(1 + (interest / MONTHS), MONTHS);  //Finds amount at end of current year, compounded monthly
        interestEarned = yearEndBalance - runningBalance;               //Finds interest earned that year
        runningBalance = yearEndBalance;                                //Reset running balance to the new year end balance

        printDetails(year++, runningBalance, interestEarned);           //Prints the current year details and updates the current year for next iteration
    }
    cout << endl;                                                       // additional endline for style in console
    t_user.setTotalNoDeposits(runningBalance);

}// balanceNoMonthlyDeposits

  // Sense tool says monthlyDeposit should not be part of the first interest calculation. The PDF example shows that it should be a part of the calculations.
void Calculations::balanceWithMonthlyDeposit(UserData& t_user) {
    /*
     * This function finds the balance & interest earned every year and displays to console.
     * The UserData object is passed in by reference allowing the total with deposits variable to be set. 
     * While that variable is not entirely useful right now, it could be helpful in future upgrades to this program.
     */
        //These Variables are obtained from the object that is passed in by reference
    double totalBalance = t_user.getInitialInvestment();            //Variable holds initial investment and is updated after every year
    double yearEndBalance = t_user.getInitialInvestment();          //Variable holds the initial investment is updated every month
    double interest = t_user.getAnnualInterest();                   //Variable holds the interest rate
    double monthlyDeposit = t_user.getMonthlyDeposit();             //Variable holds the monthly deposit
    int numberOfYears = t_user.getNumberOfYears();                  //Variable holds the number of years to compound interest

        // Variables initialized for use in while loop
    double monthlyInterest;                                         //Variable holds the monthly interest that is calculated each month
    double interestEarned;                                          //Variable holds the interest earned between years
    const int MONTHS = 12;                                          //Variable holds the constant for months in a year
    int year = 1;                                                   //Variable holds the current year

    while (year <= numberOfYears) {
        for (int month = 1; month <= MONTHS; ++month) {
            /* 
            * Below is per Sense Tool directions to NOT include interest from first month deposit 
            */
            // monthlyInterest = yearEndBalance * (interest / n); // finds interest from current month
            // yearEndBalance = yearEndBalance + monthlyDeposit + monthlyInterest; // adds current month's total to current running total

            /* 
            * Below is to incorporate adding first month's deposit to interest calculation per Airgead Functional Requirement PDF
            */

            monthlyInterest = (yearEndBalance + monthlyDeposit) * (interest / MONTHS);  //Interest calculated with first and susequent deposits
            yearEndBalance = yearEndBalance + monthlyInterest + monthlyDeposit;         //Update yearEndBalance to reflect interest earned and monthly Deposit addition
        }
        interestEarned = (yearEndBalance - totalBalance - (monthlyDeposit * 12));       //Finds interest earned that year
        totalBalance = yearEndBalance;                                                  //Set current year balance to total balance (needed for finding year's interest earned above)
        printDetails(year++, totalBalance, interestEarned);                             //Prints the current year details and updates the current year for next iteration
    }
    cout << endl;                                                                       //Additional endline for style in console
    t_user.setTotalWithDeposits(totalBalance);                                          //Sets user object's "total with deposits" private variable
    system("pause");                                                                    //Pauses system flow for user to absorb data
}

void Calculations::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
    /*
     * This function is a helper function to display the values obtained during
     * the calculations above in a formatted way.
     */
    cout << fixed << setprecision(2) << setw(YEAR_COLUMN) << right << t_year << setw(BALANCE_COLUMN) << right << t_yearEndBalance; 
    cout << setw(INTEREST_COLUMN) << right << t_interestEarned << endl << endl; //sets precision to 2 decimal points and sorts into applicable columns
}