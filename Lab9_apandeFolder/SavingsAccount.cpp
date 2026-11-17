
/**
 * @file SavingsAccount.cpp
 * @author Aayush Pande
 * @date 2026-11-16
 * @brief Implements a savings account with daily interest.
 */

#include "SavingsAccount.h"
#include <iostream>
#include <numeric>
using namespace std;

/**
 * @brief Creates a savings account with an interest rate.
 * @param accNum The account number.
 * @param initialBalance The starting balance.
 * @param customer The customer who owns the account.
 * @param interestRate The daily interest rate.
 */
SavingsAccount::SavingsAccount(
    const string& accNum,
    double initialBalance,
    const Customer& customer,
    double interestRate
)
    : Account(accNum, initialBalance, customer),
    dailyInterestRate(interestRate) {
}

/**
 * @brief Processes daily transactions and applies interest.
 * Interest is only applied when the balance is positive.
 */
void SavingsAccount::closeOfBusiness() {
    double totalDeposits = accumulate(
        deposits.begin(), deposits.end(), 0.0
    );

    double totalWithdrawals = accumulate(
        withdrawals.begin(), withdrawals.end(), 0.0
    );

    double previousBalance = balance;

    balance = previousBalance + totalDeposits
            - totalWithdrawals;

    if (balance > 0) {
        balance = balance + (balance * dailyInterestRate);
    }

    printSummary(
        previousBalance,
        totalDeposits,
        totalWithdrawals,
        balance
    );

    deposits.clear();
    withdrawals.clear();
}

/**
 * @brief Displays account information and daily interest rate.
 */
void SavingsAccount::printAccountInfo() const {
    cout << "Account Number: " << getAccountNumber() << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << dailyInterestRate * 100
        << "%" << endl;

    getCustomer().printCustomerInfo();
}
