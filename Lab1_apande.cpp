/**
 * @file Lab1_username.cpp
 * @author Aayush Pande
 * @date 2026-09-07
 * @brief A simple program to greet the user by name.
 */

#include <iostream>

int main() {
    std::cout << "Enter your first name: ";
    std::string fName;
    std::cin >> fName;

    std::cout << "Enter your last name: ";
    std::string lName;
    std::cin >> lName;

    std::cout << "Welcome to C++ Programming, " << fName << " " <<lName << "!";

    return 0;
}