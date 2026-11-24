/**
 * @file SavingsAccount.h
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Declares a savings account with interest and file output.
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

#include <string>

/**
 * @brief Represents a savings account that earns daily interest.
 */
class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
    /**
     * @brief Creates a savings account with an interest rate.
     * @param accNum The account number.
     * @param initialBalance The starting account balance.
     * @param customer The customer who owns the account.
     * @param interestRate The account's daily interest rate.
     */
    SavingsAccount(
        const std::string& accNum,
        double initialBalance,
        const Customer& customer,
        double interestRate
    );

    /**
     * @brief Processes transactions and applies daily interest.
     */
    void closeOfBusiness() override;

    /**
     * @brief Displays account information and the interest rate.
     */
    void printAccountInfo() const override;

    /**
     * @brief Saves the account number, balance, and interest rate
     * to account_summary.txt.
     */
    void Save() const;
};

#endif