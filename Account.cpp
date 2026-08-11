#include "Account.h"
using namespace std;
//getters
double Account::get_m_initialAmount() {
    return m_initialAmount;
}
double Account::get_m_monthlyDeposit() {
    return m_monthlyDeposit;
}
double Account::get_m_annualInterest() {
    return m_annualInterest;
}
int Account::get_m_noOfYears() {
    return m_noOfYears;
}
std::vector<std::vector<double>> Account::get_m_calculations() {
    return m_calculations;
}
//setters
void Account::set_m_initialAmount(double t_initialAmount) {
    m_initialAmount = t_initialAmount;
}
void Account::set_m_monthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}
void Account::set_m_annualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}
void Account::set_m_noOfYears(int t_noOfYears) {
    m_noOfYears = t_noOfYears;
}
//calculates values and places them in a vector<vector<double>>
void Account::calculate() {
    //resizing to prevent out-of-bounds access errors
    m_calculations.resize(m_noOfYears);
    for (int i = 0; i < m_calculations.size(); i++) {
        m_calculations[i].resize(5);
    }
    for (int i = 0; i < m_calculations.size(); i++) {
        int iPlus1 = i + 1;
        int iMinus1 = i - 1;
        double interestRate = (m_annualInterest / 100) + 1;
        double yearlyDeposit = m_monthlyDeposit * 12;
        m_calculations[i][0] = iPlus1; //current year
        //m_calculations[i][1] = year end balance without monthly deposits
        //m_calculations[i][2] = earned interest without monthly deposits
        //m_calculations[i][3] = year end balance with monthly deposits
        //m_calculations[i][4] = earned interest with monthly deposits
        if (i != 0) {
            m_calculations[i][1] = m_calculations[iMinus1][1] * interestRate;
            m_calculations[i][2] = m_calculations[i][1] - m_calculations[iMinus1][1];
            m_calculations[i][3] = (m_calculations[iMinus1][3] + yearlyDeposit) * interestRate;
            m_calculations[i][4] = m_calculations[i][3] - m_calculations[iMinus1][3] - yearlyDeposit;
        } else {
            m_calculations[i][1] = m_initialAmount * interestRate;
            m_calculations[i][2] = m_calculations[i][1] - m_initialAmount;
            m_calculations[i][3] = (m_initialAmount + yearlyDeposit) * interestRate;
            m_calculations[i][4] = m_calculations[i][3] - m_initialAmount - yearlyDeposit;
        }
    }
}