
/**
 * @file Customer.cpp
 * @author Aayush Pande
 * @date 2026-11-16
 * @brief Implements the Customer class.
 */

#include "Customer.h"
#include <iostream>
using namespace std;

/**
 * @brief Creates a customer with default information.
 */
Customer::Customer()
    : customerID("Unknown"), email("none@example.com") {
}

/**
 * @brief Creates a customer with an ID and email.
 * @param id The customer's unique ID.
 * @param emailAddr The customer's email address.
 */
Customer::Customer(const string& id, const string& emailAddr)
    : customerID(id), email(emailAddr) {
}

/**
 * @brief Returns the customer's ID.
 * @return The customer ID.
 */
string Customer::getCustomerID() const {
    return customerID;
}

/**
 * @brief Returns the customer's email.
 * @return The email address.
 */
string Customer::getEmail() const {
    return email;
}

/**
 * @brief Displays customer information.
 */
void Customer::printCustomerInfo() const {
    cout << "Customer ID: " << customerID << endl;
    cout << "Email: " << email << endl;
}
