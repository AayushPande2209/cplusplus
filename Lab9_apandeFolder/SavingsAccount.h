
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <string>
using namespace std;

class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
    SavingsAccount(
        const string& accNum,
        double initialBalance,
        const Customer& customer,
        double interestRate
    );

    void closeOfBusiness() override;
    void printAccountInfo() const override;
};

#endif
