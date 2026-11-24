/**
 * @file Account.cpp
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Implements general banking-account operations.
 */

#include "Account.h"

#include <iostream>
#include <numeric>

/**
 * @brief Creates an account with default values.
 */
Account::Account()
    : accountNumber("0000000000"),
    owner(),
    balance(0.0) {
}

/**
 * @brief Creates an account using supplied information.
 * @param accNum The account number.
 * @param initialBalance The starting account balance.
 * @param customer The customer who owns the account.
 */
Account::Account(
    const std::string& accNum,
    double initialBalance,
    const Customer& customer
)
    : accountNumber(accNum),
    owner(customer),
    balance(initialBalance) {
}

/**
 * @brief Destroys the account.
 */
Account::~Account() {
}

/**
 * @brief Records a deposit transaction.
 * @param amount Amount to deposit.
 * @return True when the amount is valid; otherwise false.
 */
bool Account::deposit(double amount) {
    if (amount > 0.0) {
        deposits.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Records a withdrawal transaction.
 * @param amount Amount to withdraw.
 * @return True when the amount is valid; otherwise false.
 */
bool Account::withdraw(double amount) {
    if (amount > 0.0) {
        withdrawals.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Processes all pending transactions.
 */
void Account::closeOfBusiness() {
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
 * @brief Displays a summary of the day's transactions.
 * @param previousBalance Balance before processing transactions.
 * @param totalDeposits Total deposited during the day.
 * @param totalWithdrawals Total withdrawn during the day.
 * @param newBalance Balance after processing the transactions.
 */
void Account::printSummary(
    double previousBalance,
    double totalDeposits,
    double totalWithdrawals,
    double newBalance
) const {
    std::cout << "Account Number: "
            << accountNumber << std::endl;

    std::cout << "Previous Balance: $"
            << previousBalance << std::endl;

    std::cout << "Total Deposits: $"
            << totalDeposits << std::endl;

    std::cout << "Total Withdrawals: $"
            << totalWithdrawals << std::endl;

    std::cout << "New Balance after COB: $"
            << newBalance << std::endl;
}

/**
 * @brief Returns the current account balance.
 * @return The current balance.
 */
double Account::getBalance() const {
    return balance;
}

/**
 * @brief Returns the account number.
 * @return The account number.
 */
std::string Account::getAccountNumber() const {
    return accountNumber;
}

/**
 * @brief Returns the customer who owns the account.
 * @return The account's Customer object.
 */
Customer Account::getCustomer() const {
    return owner;
}

/**
 * @brief Displays account and customer information.
 */
void Account::printAccountInfo() const {
    std::cout << "Account Number: "
            << accountNumber << std::endl;

    std::cout << "Current Balance: $"
            << balance << std::endl;

    owner.printCustomerInfo();
}

/**
 * @brief Displays all pending deposits and withdrawals.
 */
void Account::printTransactions() const {
    std::cout << "Deposits: ";

    for (double amount : deposits) {
        std::cout << "$" << amount << " ";
    }

    std::cout << std::endl << "Withdrawals: ";

    for (double amount : withdrawals) {
        std::cout << "$" << amount << " ";
    }

    std::cout << std::endl;
}