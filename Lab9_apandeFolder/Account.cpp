
/**
 * @file Account.cpp
 * @author Aayush Pande
 * @date 2026-11-16
 * @brief Implements banking account operations and transactions.
 */

#include "Account.h"
#include <iostream>
#include <numeric>
using namespace std;

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
 * @param initialBalance The starting balance.
 * @param customer The customer who owns the account.
 */
Account::Account(
    const string& accNum,
    double initialBalance,
    const Customer& customer
)
    : accountNumber(accNum),
    owner(customer),
    balance(initialBalance) {
}

/**
 * @brief Destroys the account object.
 */
Account::~Account() {
}

/**
 * @brief Records a deposit transaction.
 * @param amount Amount to deposit.
 * @return True if the deposit is valid, otherwise false.
 */
bool Account::deposit(double amount) {
    if (amount > 0) {
        deposits.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Records a withdrawal transaction.
 * @param amount Amount to withdraw.
 * @return True if the withdrawal is valid, otherwise false.
 */
bool Account::withdraw(double amount) {
    if (amount > 0) {
        withdrawals.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Processes transactions at the end of the day.
 */
void Account::closeOfBusiness() {
    double totalDeposits = accumulate(
        deposits.begin(), deposits.end(), 0.0
    );

    double totalWithdrawals = accumulate(
        withdrawals.begin(), withdrawals.end(), 0.0
    );

    double previousBalance = balance;

    balance = previousBalance + totalDeposits
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
 * @param previousBalance Balance before transactions.
 * @param totalDeposits Total deposited during the day.
 * @param totalWithdrawals Total withdrawn during the day.
 * @param newBalance Balance after closing.
 */
void Account::printSummary(
    double previousBalance,
    double totalDeposits,
    double totalWithdrawals,
    double newBalance
) const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Previous Balance: $" << previousBalance << endl;
    cout << "Total Deposits: $" << totalDeposits << endl;
    cout << "Total Withdrawals: $" << totalWithdrawals << endl;
    cout << "New Balance after COB: $" << newBalance << endl;
}

/**
 * @brief Returns the current account balance.
 * @return Current balance.
 */
double Account::getBalance() const {
    return balance;
}

/**
 * @brief Returns the account number.
 * @return Account number.
 */
string Account::getAccountNumber() const {
    return accountNumber;
}

/**
 * @brief Returns the account owner.
 * @return Customer object.
 */
Customer Account::getCustomer() const {
    return owner;
}

/**
 * @brief Displays account and customer information.
 */
void Account::printAccountInfo() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    owner.printCustomerInfo();
}

/**
 * @brief Displays pending deposits and withdrawals.
 */
void Account::printTransactions() const {
    cout << "Deposits: ";

    for (double amount : deposits) {
        cout << "$" << amount << " ";
    }

    cout << endl << "Withdrawals: ";

    for (double amount : withdrawals) {
        cout << "$" << amount << " ";
    }

    cout << endl;
}
