/**
 * @file Lab3_username.cpp
 * @author Your Name
 * @date 2025-01-29
 * @brief A menu-driven program to calculate areas of rectangles and circles.
 */

#include <iostream>

int main(){
    std::cout << "Menu";
    std::cout << "Option 1: Calculate the Area of a Rectangle";
    std::cout << "Option 2: Calculate the Area of a Circle";
    std::cout << "Option 3: Exit";

    int option;

    std::cout << "Please make a menu selection: ";
    std::cout << option;

    switch(option){
        case 1:
        double length;
        double width;
        std::cout << 'Please enter the length of the rectangle: ';
        std::cin >> length;
        std::cout << 'Please enter the width of the rectangle: ';
        std::cin >> width;
        std::cout << 'The area of the rectangle is: ' << length * width;
        break;

        case 2:
        double pi = 3.14;
        double radius;
        std::cout << 'Please enter the radius of the Circle: ';
        std::cin >> radius;
        std::cout << 'The area of the circle is: ' << length * width;
        break;


    }

    

}

