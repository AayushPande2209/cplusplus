/**
 * @file Customer.h
 * @author Aayush Pande
 * @date 2026-11-23
 * @brief Declares the Customer class used by bank accounts.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

/**
 * @brief Stores identifying information about a bank customer.
 */
class Customer {
private:
    std::string customerID;
    std::string email;

public:
    /**
     * @brief Creates a customer with default information.
     */
    Customer();

    /**
     * @brief Creates a customer with an ID and email address.
     * @param id The customer's unique ID.
     * @param emailAddr The customer's email address.
     */
    Customer(
        const std::string& id,
        const std::string& emailAddr
    );

    /**
     * @brief Returns the customer's ID.
     * @return The customer ID.
     */
    std::string getCustomerID() const;

    /**
     * @brief Returns the customer's email address.
     * @return The customer's email address.
     */
    std::string getEmail() const;

    /**
     * @brief Displays the customer's information.
     */
    void printCustomerInfo() const;
};

#endif