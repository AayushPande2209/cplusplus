/**
 * @file Lab4_apande.cpp
 * @author Aayush Pande
 * @date 2026-09-29
 * @brief A program to generate a multiplication table with input validation.
 */

#include <iostream>

int main() {

    int maxDigit;

    std::cout << "Please enter the maximum digit for the multiplication table."
            << std::endl;
    std::cout << "The digit must be greater than 4 and less than 10"
            << std::endl;

    do {
        std::cout << "Max Digit: ";
        std::cin >> maxDigit;

        if (maxDigit <= 4 || maxDigit >= 10) {
            std::cout << "Error: The max digit must be greater than 4 and less than 10. "
                    << "Please try again." << std::endl;
        }

    } while (maxDigit <= 4 || maxDigit >= 10);

    for (int row = 1; row <= maxDigit; row++) {

        for (int column = 1; column <= maxDigit; column++) {
            std::cout << row * column << "\t";
        }

        std::cout << std::endl;
    }

    return 0;
}

