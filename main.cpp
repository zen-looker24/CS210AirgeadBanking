#include <vector>
#include <iostream>
#include "UserInterface.h" //contains functions for printing the UI
#include "Account.h" //contains the class Account
using namespace std;

int main() {
    //Variable declarations
    string placeholder;
    Account account;
    double input;
    int inputINT;
    int choice;
    //UI printing
    printWelcome();
    printNoInput();
    //Printing directions, getting input values, assigning them to the object account
    printCenteredLine(" Initial Amount: ");
    account.set_m_initialAmount(checkNewValue());
    printCenteredLine(" Monthly Deposit Amount: ");
    account.set_m_monthlyDeposit(checkNewValue());
    printCenteredLine(" Annual Interest Amount: ");
    account.set_m_annualInterest(checkNewValue());
    printCenteredLine(" Amount Of Years: ");
        //Account's variable noOfYears is an integer, input must be typecast to an integer
    input = checkNewValue();
    inputINT = static_cast<int>(input);
    account.set_m_noOfYears(inputINT);
    //reprinting the original table with input values
    printWithInput(account.get_m_initialAmount(), account.get_m_monthlyDeposit(), account.get_m_annualInterest(), account.get_m_noOfYears());
    cin >> placeholder;
    //calculating and printing tables
    account.calculate();
    printReport(account.get_m_calculations());
    //options loop
    choice = optionMenu();
    while (choice != 6) {
        if (choice >= 1 && choice <= 4) {
            input = checkNewValue();
            inputINT = static_cast<int>(input);
        }
        switch (choice) {
            case 1: account.set_m_initialAmount(input); break; //changes initial amount
            case 2: account.set_m_monthlyDeposit(input); break; //changes monthly deposit
            case 3: account.set_m_annualInterest(input); break; //changes annual interest
            case 4: //changes number of years
                account.set_m_noOfYears(inputINT);
                break;
            case 5: //recalculates and prints tables
                account.calculate();
                printReport(account.get_m_calculations());
                break;
        }
        choice = optionMenu(); //choose a new option
    }
    printGoodbye();
    return 0;
}
