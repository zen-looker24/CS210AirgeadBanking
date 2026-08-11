#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int numberLength(auto t_number) {
    //Takes a number as input and returns its length as a string with two decimals
    //ie, the number 12.3455 would return 5
    int length = 4;
    double modulo = 10;
    while (fmod(t_number, modulo) != t_number) {
        modulo *= 10;
        length++;
    }
    return length;
}
void printCenteredLine(string t_text = "", char t_fill = '*') {
    if (t_text.empty()) { //prints only t_fill 60 times if t_text is empty
        cout << setw(60) << setfill(t_fill) << t_text << endl;
    } else { //calculates padding and prints a left and right side of the line
        if (t_text.length() % 2 != 0) {
            t_text += " ";
        }
        int padding = 60 - t_text.length();
        int rightFill = padding / 2;
        int leftFill = rightFill + t_text.length();
        cout << setw(leftFill) << setfill(t_fill) << right << t_text;
        cout << setw(rightFill) << setfill(t_fill) << "" << endl;
    }

}
void printLeftLine(string t_text, bool t_decimal = true) {
    //prints a left aligned line with asterisks at either end
    //t_decimal prints numbers to 2 decimal places if true and 0 if false
    int precision;
    t_decimal ? precision = 2 : precision = 0;
    t_text = "* " + t_text;
    cout << setw(59) << setfill(' ') << left << fixed << setprecision(precision) << t_text;
    cout << "*" << endl;
}
void printWelcome() {
    printCenteredLine();
    printCenteredLine(" Welcome to the Airgead Banking App ");
}
void printNoInput() {
    printCenteredLine();
    printCenteredLine(" Data Input ");
    printLeftLine("Initial Investment Amount: ");
    printLeftLine("Monthly Deposit Amount: ");
    printLeftLine("Annual Interest Rate: ");
    printLeftLine("Number Of Years: ", false);
    printCenteredLine();
    printCenteredLine(" To enter values, type a number for ");
    printCenteredLine(" the corresponding item, then press enter. ");
    printCenteredLine();
}
void printWithInput(double t_initialAmount, double t_monthlyDeposit, double t_annualInterest, int t_noOfYears) {
    printCenteredLine();
    printCenteredLine(" Data Input ");
    string initAmt = "Initial Investment Amount: $" + to_string(t_initialAmount).substr(0, numberLength(t_initialAmount));
    printLeftLine(initAmt);
    string deposAmt = "Monthly Deposit Amount: $" + to_string(t_monthlyDeposit).substr(0, numberLength(t_monthlyDeposit));
    printLeftLine(deposAmt);
    string interestRate = "Annual Interest Rate: " + to_string(t_annualInterest).substr(0, numberLength(t_annualInterest)) + "%";
    printLeftLine(interestRate);
    string years = "Number Of Years: " + to_string(t_noOfYears);
    printLeftLine(years, false);
    printCenteredLine();
    cout << "Press any key and enter to continue" << endl;
}
int optionMenu() {
    printCenteredLine();
    printCenteredLine(" Options ");
    printLeftLine("[1] Change Initial Investment Amount");
    printLeftLine("[2] Change Monthly Deposit Amount");
    printLeftLine("[3] Change Annual Interest Rate");
    printLeftLine("[4] Change Number Of Years");
    printLeftLine("[5] Reprint Tables");
    printLeftLine("[6] Quit");
    printCenteredLine();
    int choice = 0;
    //loop continues while choice is not 1-6
    while (choice < 1 || choice > 6) {
        printCenteredLine(" Enter a number to select an option ");
        cin >> choice;
        if (choice < 1 || choice > 6) {
            printCenteredLine(" Invalid choice ");
        }
    }
    return choice;
}
double checkNewValue() {
    double value;
    printCenteredLine(" Enter the new value ");
    cin >> value;
    //loop only continues if value is negative
    while (value < 0) {
        printCenteredLine(" Please enter a positive number ");
        cin >> value;
    }
    return value;
}
void printGoodbye() {
    printCenteredLine();
    printCenteredLine(" Thank you for using the Airgead ");
    printCenteredLine(" Banking App. Goodbye! ");
    printCenteredLine();
}
void printTableHeader(std::string t_text) {
    printCenteredLine("", '-');
    printCenteredLine(t_text, ' ');
    printCenteredLine("", '-');
    cout << "|" << setw(9) << setfill(' ') << right << "Year |";
    cout << setw(25) << setfill(' ') << right << "Year End Balance |";
    cout << setw(25) << setfill(' ') << right << "Earned Interest |" << endl;
    printCenteredLine("", '-');
}
void printReport(std::vector<std::vector<double>> t_calculations) {
    //t_calculations[i] = values for year i
    //t_calculations[i][0] = current year
    //t_calculations[i][1] = year end balance without monthly deposits
    //t_calculations[i][2] = earned interest without monthly deposits
    //t_calculations[i][3] = year end balance with monthly deposits
    //t_calculations[i][4] = earned interest with monthly deposits
    printTableHeader(" Balance and Interest Without Monthly Deposits ");
    for (int i = 0; i < t_calculations.size(); i++) {
        cout << setfill(' ');
        cout << "|" << setw(7) << right << fixed << setprecision(0) << t_calculations[i][0] << " |";
        string endBalance = "$" + to_string(t_calculations[i][1]).substr(0, numberLength(t_calculations[i][1]));
        cout << setw(23) << right << fixed << setprecision(2) << endBalance << " |";
        string earnedInterest = "$" + to_string(t_calculations[i][2]).substr(0, numberLength(t_calculations[i][2]));
        cout << setw(23) << right << fixed << setprecision(2) << earnedInterest << " |" << endl;
    }
    printCenteredLine("", '-');
    cout << endl;
    printTableHeader(" Balance and Interest With Monthly Deposits ");
    for (int i = 0; i < t_calculations.size(); i++) {
        cout << setfill(' ');
        cout << "|" << setw(7) << right << fixed << setprecision(0) << t_calculations[i][0] << " |";
        string endBalance = "$" + to_string(t_calculations[i][3]).substr(0, numberLength(t_calculations[i][3]));
        cout << setw(23) << right << fixed << setprecision(2) << endBalance << " |";
        string earnedInterest = "$" + to_string(t_calculations[i][4]).substr(0, numberLength(t_calculations[i][4]));
        cout << setw(23) << right << fixed << setprecision(2) << earnedInterest << " |" << endl;
    }
    printCenteredLine("", '-');
    cout << endl;
}