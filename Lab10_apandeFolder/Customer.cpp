/**
 * @file Customer.cpp
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Implements the Customer class.
 */

#include "Customer.h"

#include <iostream>

/**
 * @brief Creates a customer with default information.
 */
Customer::Customer()
    : customerID("Unknown"),
    email("none@example.com") {
}

/**
 * @brief Creates a customer with an ID and email address.
 * @param id The customer's unique ID.
 * @param emailAddr The customer's email address.
 */
Customer::Customer(
    const std::string& id,
    const std::string& emailAddr
)
    : customerID(id),
    email(emailAddr) {
}

/**
 * @brief Returns the customer's ID.
 * @return The customer ID.
 */
std::string Customer::getCustomerID() const {
    return customerID;
}

/**
 * @brief Returns the customer's email address.
 * @return The customer's email address.
 */
std::string Customer::getEmail() const {
    return email;
}

/**
 * @brief Displays the customer's information.
 */
void Customer::printCustomerInfo() const {
    std::cout << "Customer ID: " << customerID << std::endl;
    std::cout << "Email: " << email << std::endl;
}