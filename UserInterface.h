#ifndef AIRGEADBANKING_USERINTERFACE_H
#define AIRGEADBANKING_USERINTERFACE_H
#include <string>
#include <vector>
//Requires C++11 or higher due to the use of to_string()
int numberLength(auto t_number); //returns an integer representing the length of a number with two decimal places
void printCenteredLine(std::string t_text, char t_fill = '*');
void printLeftLine(std::string t_text, bool t_decimal = true);
void printWelcome();
void printNoInput(); //prints the different value titles with no values next to them
void printWithInput(double t_initialAmount, double t_monthlyDeposit, double t_annualInterest, int t_noOfYears);
int optionMenu(); //returns chosen option number from the menu
double checkNewValue(); //asks for an input value and returns it when it is positive
void printGoodbye();
void printTableHeader(std::string t_text); //prints table title and column names
void printReport(std::vector<std::vector<double>> t_calculations); //prints table values from a vector
#endif //AIRGEADBANKING_USERINTERFACE_H
