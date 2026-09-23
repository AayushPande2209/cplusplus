/**
 * @file Lab3_username.cpp
 * @author Your Name
 * @date 2025-01-29
 * @brief A menu-driven program to calculate areas of rectangles and circles.
 */

#include <iostream>

int main(){
    std::cout << "Menu";
    std::cout << "Option 1: Calculate the Area of a Rectangle" << std::endl;
    std::cout << "Option 2: Calculate the Area of a Circle" << std::endl;
    std::cout << "Option 3: Exit" << std::endl;

    int option;

    std::cout << "Please make a menu selection: " << std::endl;
    std::cin >> option;

    switch(option){
        case 1:
        {
        double length;
        double width;
        std::cout << "Please enter the length of the rectangle: " << std::endl;
        std::cin >> length;
        std::cout << "Please enter the width of the rectangle: " << std::endl;
        std::cin >> width;
        std::cout << "The area of the rectangle is: " << length * width;
        break;
        }

        case 2:
        {
        const double PI = 3.14159;
        double radius;
        std::cout << "Please enter the radius of the Circle: " << std::endl;
        std::cin >> radius;
        std::cout << "The area of the circle is: " << PI * (radius * radius);
        break;
        }

        case 3:
        {
        std::cout << "Exiting" << std::endl;
        break; } 

        default: 
        { 
        std::cout << "Invalid menu selection." << std::endl; break; 
    }


    }

    

}

