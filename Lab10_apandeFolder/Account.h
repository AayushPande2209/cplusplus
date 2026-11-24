/**
 * @file Account.h
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Declares the base Account class.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

#include <string>
#include <vector>

/**
 * @brief Represents a general bank account and its pending transactions.
 */
class Account {
private:
    std::string accountNumber;
    Customer owner;

protected:
    double balance;
    std::vector<double> deposits;
    std::vector<double> withdrawals;

    /**
     * @brief Displays a summary of the day's transactions.
     * @param previousBalance Balance before processing transactions.
     * @param totalDeposits Total deposited during the day.
     * @param totalWithdrawals Total withdrawn during the day.
     * @param newBalance Balance after processing the transactions.
     */
    void printSummary(
        double previousBalance,
        double totalDeposits,
        double totalWithdrawals,
        double newBalance
    ) const;

public:
    /**
     * @brief Creates an account with default values.
     */
    Account();

    /**
     * @brief Creates an account using the supplied information.
     * @param accNum The account number.
     * @param initialBalance The starting account balance.
     * @param customer The customer who owns the account.
     */
    Account(
        const std::string& accNum,
        double initialBalance,
        const Customer& customer
    );

    /**
     * @brief Destroys the account.
     */
    virtual ~Account();

    /**
     * @brief Records a deposit transaction.
     * @param amount Amount to deposit.
     * @return True when the amount is valid; otherwise false.
     */
    bool deposit(double amount);

    /**
     * @brief Records a withdrawal transaction.
     * @param amount Amount to withdraw.
     * @return True when the amount is valid; otherwise false.
     */
    bool withdraw(double amount);

    /**
     * @brief Processes the pending transactions.
     */
    virtual void closeOfBusiness();

    /**
     * @brief Returns the current account balance.
     * @return The current balance.
     */
    double getBalance() const;

    /**
     * @brief Returns the account number.
     * @return The account number.
     */
    std::string getAccountNumber() const;

    /**
     * @brief Returns the customer who owns the account.
     * @return The account's Customer object.
     */
    Customer getCustomer() const;

    /**
     * @brief Displays account and customer information.
     */
    virtual void printAccountInfo() const;

    /**
     * @brief Displays all pending deposits and withdrawals.
     */
    void printTransactions() const;
};

#endif