/**
 * @file Lab2_apande.cpp
 * @author Aayush Pande
 * @date 2025-01-22
 * @brief A program to calculate the perimeter of a rectangle from user input.
 */

#include <iostream>

int main() {
    double rect_length;
    std::cout << "Please enter the length of the rectangle: ";
    std::cin >> rect_length;

    double rect_width;
    std::cout << "Please enter the width of the rectangle: ";
    std::cin >> rect_width;

    double rect_perimeter = 2 * (rect_length + rect_width);

    std::cout << "The perimeter of the rectangle is: " << rect_perimeter;


}