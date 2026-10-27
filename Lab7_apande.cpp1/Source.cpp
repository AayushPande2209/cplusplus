/**
 * @file Source.cpp
 * @author Aayush Pande
 * @date 2026-10-26
 * @brief A banking simulation that interacts with Account and Customer objects.
 */

#include <iostream>
#include "Account.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking application.
 *
 * Creates a customer and account, then processes deposits, withdrawals,
 * close-of-business balancing, and quitting through a menu-driven loop.
 *
 * @return 0 to indicate success.
 */
int main()
{
    // Use dummy data for the customer and account for this simulation.
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double depositAmount;

            cout << "Enter deposit amount: ";
            cin >> depositAmount;

            if (isAmountValid(depositAmount))
            {
                account.deposit(depositAmount);
            }
            else
            {
                cout << "Invalid amount. Amount must be greater than 0."
                     << endl;
            }

            break;
        }

        case WITHDRAWAL:
        {
            double withdrawalAmount;

            cout << "Enter withdrawal amount: ";
            cin >> withdrawalAmount;

            if (isAmountValid(withdrawalAmount))
            {
                account.withdraw(withdrawalAmount);
            }
            else
            {
                cout << "Invalid amount. Amount must be greater than 0."
                     << endl;
            }

            break;
        }

        case CLOSE_OF_BUSINESS:
            account.closeOfBusiness();
            break;
        }

        menuChoice = getMenuOption();
    }

    return 0;
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    }
    while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}