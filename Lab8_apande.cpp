/**
 * @file Lab8_apande.cpp
 * @author Aayush Pande
 * @date 2026-11-02
 * @brief Demonstrates stack and heap memory, pointers, and references.
 *
 * Resources: CSCI 2521 Week 8 slides and zyBooks Chapter 8.
 */

#include <iostream>

using namespace std;

/**
 * @brief Creates stack and heap integers and accesses the stack integer
 * through both a pointer and a reference.
 *
 * @return 0 when the program finishes successfully.
 */
int main()
{
    int stackInt = 10;
    int* heapInt = new int(20);
    int* ptrToStack = &stackInt;
    int& refToStack = stackInt;

    cout << "Stack Variable (stackInt):\n";
    cout << "  Value: " << stackInt << '\n';
    cout << "  Address: " << &stackInt << "\n\n";

    cout << "Heap Variable (heapInt):\n";
    cout << "  Value: " << *heapInt << '\n';
    cout << "  Address: " << heapInt << "\n\n";

    cout << "Pointer to Stack (ptrToStack):\n";
    cout << "  Value Pointed To: " << *ptrToStack << '\n';
    cout << "  Address Stored: " << ptrToStack << "\n\n";

    cout << "Reference to Stack (refToStack):\n";
    cout << "  Value Referred To: " << refToStack << '\n';
    cout << "  Address: " << &refToStack << '\n';

    delete heapInt;
    heapInt = nullptr;

    return 0;
}