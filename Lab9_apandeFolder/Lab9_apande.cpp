
/**
 * @file lab9_apande.cpp
 * @author Aayush Pande
 * @date 2026-11-16
 * @brief Demonstrates inheritance and polymorphism using
 * a banking system with savings accounts and daily interest.
 */

#include <iostream>
#include <limits>
#include "SavingsAccount.h"
using namespace std;

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

/**
 * @brief Runs the banking system and demonstrates polymorphism.
 * @return 0 if the program exits successfully.
 */
int main() {
    Customer customer("0123456789", "customer@cscc.edu");

    Account* account = new SavingsAccount(
        "5423678409",
        100.00,
        customer,
        0.02
    );

    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT) {
        double deposit = 0;
        double withdrawal = 0;

        switch (menuChoice) {
            case DEPOSIT:
                deposit = getDepositAmount();
                account->deposit(deposit);
                break;

            case WITHDRAWAL:
                withdrawal = getWithdrawalAmount();
                account->withdraw(withdrawal);
                break;

            case CLOSE_OF_BUSINESS:
                account->closeOfBusiness();
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
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

/**
 * @brief Gets a valid menu selection from the user.
 * @return The selected menu option.
 */
int getMenuOption() {
    int choice = 0;

    do {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
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
 * @return True if the choice is valid, otherwise false.
 */
bool isMenuChoiceValid(int choice) {
    return choice >= DEPOSIT && choice <= QUIT;
}

/**
 * @brief Checks whether a transaction amount is positive.
 * @param amount The transaction amount.
 * @return True if the amount is valid, otherwise false.
 */
bool isAmountValid(double amount) {
    return amount > 0 && amount <=
        numeric_limits<double>::max();
}

/**
 * @brief Displays an invalid menu selection message.
 */
void printInvalidMenuChoiceMessage() {
    cout << "Invalid option selected. Please try again."
        << endl;
}

/**
 * @brief Gets a valid deposit amount from the user.
 * @return The deposit amount.
 */
double getDepositAmount() {
    double deposit = 0;

    do {
        cout << "Please enter the deposit amount: $";

        if (!(cin >> deposit)) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            deposit = 0;
        }

        if (!isAmountValid(deposit)) {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}

/**
 * @brief Gets a valid withdrawal amount from the user.
 * @return The withdrawal amount.
 */
double getWithdrawalAmount() {
    double withdrawal = 0;

    do {
        cout << "Please enter the withdrawal amount: $";

        if (!(cin >> withdrawal)) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            withdrawal = 0;
        }

        if (!isAmountValid(withdrawal)) {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

/**
 * @brief Displays an invalid transaction amount message.
 */
void printInvalidAmountMessage() {
    cout << "The dollar amount must be greater than $0.00."
        << " Please try again." << endl;
}
