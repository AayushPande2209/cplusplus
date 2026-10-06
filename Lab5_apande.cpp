/**
 * @file Lab5_username.cpp
 * @author Aayush Pande
 * @date 2026-10-05
 * @brief This program asks the user for a maximum digit and prints
 *        a multiplication table using functions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints an error message when the user enters an invalid number.
 */
void printInputValidationError()
{
    cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
}

/**
 * @brief Checks if the user's input is within the valid range.
 * @param input The number entered by the user.
 * @return True if the input is greater than 4 and less than 10, false otherwise.
 */
bool isMaxDigitInputValid(int input)
{
    if (input > 4 && input < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Gets a valid maximum digit from the user.
 * @return The valid maximum digit entered by the user.
 */
int getMaxDigitInput()
{
    int maxDigit;

    cout << "Please enter the maximum digit for the multiplication table. "
         << "The digit must be greater than 4 and less than 10." << endl;

    cout << "Max Digit: ";
    cin >> maxDigit;

    while (!isMaxDigitInputValid(maxDigit))
    {
        printInputValidationError();

        cout << "Max Digit: ";
        cin >> maxDigit;
    }

    return maxDigit;
}

/**
 * @brief Prints a multiplication table from 1 to the maximum digit.
 * @param maxDigit The highest number to include in the table.
 */
void printMultiplicationTable(int maxDigit)
{
    for (int row = 1; row <= maxDigit; row++)
    {
        for (int column = 1; column <= maxDigit; column++)
        {
            cout << row * column << "\t";
        }

        cout << endl;
    }
}

/**
 * @brief Runs the multiplication table program.
 * @return 0 when the program finishes successfully.
 */
int main()
{
    int maxDigit = getMaxDigitInput();

    printMultiplicationTable(maxDigit);

    return 0;
}