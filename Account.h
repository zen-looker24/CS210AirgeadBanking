#ifndef AIRGEADBANKING_ACCOUNT_H
#define AIRGEADBANKING_ACCOUNT_H
#include <vector>
class Account {
    private:
        double m_initialAmount = 0;
        double m_monthlyDeposit = 0;
        double m_annualInterest = 0;
        int m_noOfYears = 0;
        std::vector<std::vector<double>> m_calculations;
    public:
        double get_m_initialAmount();
        double get_m_monthlyDeposit();
        double get_m_annualInterest();
        int get_m_noOfYears();
        std::vector<std::vector<double>> get_m_calculations();
        void set_m_initialAmount(double t_initialAmount);
        void set_m_monthlyDeposit(double t_monthlyDeposit);
        void set_m_annualInterest(double t_annualInterest);
        void set_m_noOfYears(int t_noOfYears);
        void calculate(); //calculates values and places them in m_calculations
};
#endif //AIRGEADBANKING_ACCOUNT_H
