#include <iostream>

int main() {
    double x;
    double y;
    char op;

    std::cout << "Enter a Number: ";
    std::cin >> x;

    std::cout << "Enter an operator: ";
    std::cin >> op;

    std::cout << "Enter a Number: ";
    std::cin >> y;

    switch (op)
    {
    case '+':
        std::cout << x + y;
        break;

    case '-':
        std::cout << x - y;
        break;
    
    case '*':
        std::cout << x * y;
        break;

    case '/':
        std::cout << x / y;
        break;
    
    default:
        break;
    }

    return 0;
}

