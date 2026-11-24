/**
 * @file Lab10_apande.cpp
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Demonstrates file output through a SavingsAccount member
 * function that writes account information to a text file.
 */

#include "SavingsAccount.h"

#include <iostream>
#include <limits>

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int SAVE = 4;
const int QUIT = 5;

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

/**
 * @brief Runs the banking system and demonstrates saving account data.
 * @return 0 when the program exits successfully.
 */
int main() {
    Customer customer(
        "0123456789",
        "customer@cscc.edu"
    );

    SavingsAccount* account = new SavingsAccount(
        "5423678409",
        100.00,
        customer,
        0.02
    );

    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT) {
        switch (menuChoice) {
            case DEPOSIT:
                account->deposit(getDepositAmount());
                break;

            case WITHDRAWAL:
                account->withdraw(getWithdrawalAmount());
                break;

            case CLOSE_OF_BUSINESS:
                account->closeOfBusiness();
                account->Save();

                std::cout
                    << "Account summary saved to "
                    << "account_summary.txt."
                    << std::endl;
                break;

            case SAVE:
                account->Save();

                std::cout
                    << "Account summary saved to "
                    << "account_summary.txt."
                    << std::endl;
                break;

            default:
                break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
    account = nullptr;

    return 0;
}

/**
 * @brief Displays the banking menu.
 */
void printMenu() {
    std::cout << "\nCSCC Bank and Trust" << std::endl;
    std::cout << "Select an option:" << std::endl;
    std::cout << DEPOSIT << ". Make a deposit" << std::endl;
    std::cout << WITHDRAWAL << ". Make a withdrawal" << std::endl;
    std::cout << CLOSE_OF_BUSINESS
            << ". Close of Business" << std::endl;
    std::cout << SAVE << ". Save account summary" << std::endl;
    std::cout << QUIT << ". Quit" << std::endl;
}

/**
 * @brief Gets a valid menu selection from the user.
 * @return The selected menu option.
 */
int getMenuOption() {
    int choice = 0;

    do {
        printMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            choice = 0;
        }

        if (!isMenuChoiceValid(choice)) {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

/**
 * @brief Checks whether a menu choice is valid.
 * @param choice The selected menu option.
 * @return True when the choice is valid; otherwise false.
 */
bool isMenuChoiceValid(int choice) {
    return choice >= DEPOSIT && choice <= QUIT;
}

/**
 * @brief Checks whether a transaction amount is positive.
 * @param amount The transaction amount.
 * @return True when the amount is valid; otherwise false.
 */
bool isAmountValid(double amount) {
    return amount > 0.0;
}

/**
 * @brief Displays an invalid-menu-selection message.
 */
void printInvalidMenuChoiceMessage() {
    std::cout
        << "Invalid option selected. Please try again."
        << std::endl;
}

/**
 * @brief Gets a valid deposit amount from the user.
 * @return The validated deposit amount.
 */
double getDepositAmount() {
    double deposit = 0.0;

    do {
        std::cout << "Please enter the deposit amount: $";

        if (!(std::cin >> deposit)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            deposit = 0.0;
        }

        if (!isAmountValid(deposit)) {
            printInvalidAmountMessage();
        }
    } while (!isAmountValid(deposit));

    return deposit;
}

/**
 * @brief Gets a valid withdrawal amount from the user.
 * @return The validated withdrawal amount.
 */
double getWithdrawalAmount() {
    double withdrawal = 0.0;

    do {
        std::cout << "Please enter the withdrawal amount: $";

        if (!(std::cin >> withdrawal)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            withdrawal = 0.0;
        }

        if (!isAmountValid(withdrawal)) {
            printInvalidAmountMessage();
        }
    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

/**
 * @brief Displays an invalid-transaction-amount message.
 */
void printInvalidAmountMessage() {
    std::cout
        << "The dollar amount must be greater than $0.00. "
        << "Please try again."
        << std::endl;
}