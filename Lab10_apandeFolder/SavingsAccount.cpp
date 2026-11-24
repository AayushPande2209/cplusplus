/**
 * @file SavingsAccount.cpp
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Implements a savings account with interest and file output.
 */

#include "SavingsAccount.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>

/**
 * @brief Creates a savings account with an interest rate.
 * @param accNum The account number.
 * @param initialBalance The starting account balance.
 * @param customer The customer who owns the account.
 * @param interestRate The account's daily interest rate.
 */
SavingsAccount::SavingsAccount(
    const std::string& accNum,
    double initialBalance,
    const Customer& customer,
    double interestRate
)
    : Account(accNum, initialBalance, customer),
    dailyInterestRate(interestRate) {
}

/**
 * @brief Processes transactions and applies daily interest.
 */
void SavingsAccount::closeOfBusiness() {
    const double totalDeposits = std::accumulate(
        deposits.begin(),
        deposits.end(),
        0.0
    );

    const double totalWithdrawals = std::accumulate(
        withdrawals.begin(),
        withdrawals.end(),
        0.0
    );

    const double previousBalance = balance;

    balance = previousBalance
        + totalDeposits
        - totalWithdrawals;

    if (balance > 0.0) {
        balance += balance * dailyInterestRate;
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
 * @brief Displays account information and the interest rate.
 */
void SavingsAccount::printAccountInfo() const {
    std::cout << "Account Number: "
            << getAccountNumber() << std::endl;

    std::cout << "Current Balance: $"
            << balance << std::endl;

    std::cout << "Interest Rate: "
              << dailyInterestRate * 100.0
            << "%" << std::endl;

    getCustomer().printCustomerInfo();
}

/**
 * @brief Saves the account number, balance, and interest rate
 * to account_summary.txt.
 */
void SavingsAccount::Save() const {
    std::ofstream outputFile("account_summary.txt");

    outputFile << "Account Number: "
            << getAccountNumber() << std::endl;

    outputFile << "Current Balance: $"
            << std::fixed
            << std::setprecision(2)
            << balance
            << std::endl;

    outputFile << "Daily Interest Rate: "
            << dailyInterestRate
            << std::endl;

    outputFile.close();
}