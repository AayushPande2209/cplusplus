
/**
 * @file Lab1_apande.cpp
 * @author Aayush Pande
 * @date 2026-10-18
 * @brief This program validates UPC-A barcodes using the check digit algorithm.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @brief Checks whether a UPC contains exactly 12 numeric digits.
 * @param upc The UPC code entered by the user.
 * @return True if the UPC has 12 digits, otherwise false.
 */
bool isValidFormat(string upc) {
    if (upc.length() != 12) {
        return false;
    }

    for (char digit : upc) {
        if (!isdigit(static_cast<unsigned char>(digit))) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Calculates the check digit using the first 11 UPC digits.
 * @param upc The UPC code.
 * @return The calculated check digit.
 */
int calculateCheckDigit(string upc) {
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < 11; i++) {
        int digit = upc[i] - '0';

        if (i % 2 == 0) {
            oddSum += digit;
        } else {
            evenSum += digit;
        }
    }

    int total = (oddSum * 3) + evenSum;
    int remainder = total % 10;

    if (remainder == 0) {
        return 0;
    }

    return 10 - remainder;
}

/**
 * @brief Determines whether a UPC code is valid.
 * @param upc The UPC code to validate.
 * @return True if the UPC is valid, otherwise false.
 */
bool validateUPC(string upc) {
    if (!isValidFormat(upc)) {
        return false;
    }

    int checkDigit = upc[11] - '0';
    int calculatedDigit = calculateCheckDigit(upc);

    return checkDigit == calculatedDigit;
}

/**
 * @brief Runs the UPC validation program and allows repeated tests.
 * @return 0 when the program finishes successfully.
 */
int main() {
    string upc;
    char choice;

    do {
        cout << "Do you have a UPC number to test? (y or n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the 12-digit UPC code: ";
            cin >> upc;

            if (validateUPC(upc)) {
                cout << "UPC code " << upc << " is valid." << endl;
            } else {
                cout << "UPC code " << upc << " is invalid." << endl;
            }

            cout << endl;
        }

    } while (choice != 'n' && choice != 'N');

    cout << "Program ended." << endl;

    return 0;
}
