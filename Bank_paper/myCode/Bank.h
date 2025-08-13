/*
 * Bank.h
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#ifndef BANK_H_
#define BANK_H_
#include <memory>
#include <map>
#include <vector>
class Customer;
/**
 * Represents the Bank. In the scope of this exercise, the properties
 * of the bank are reduced to "a bank has customers".
 */
class Bank
{
private:
	/** The number of the next customer that is created by an
	     * invocation of #createCustomer() */
	unsigned int nextCustomerNumber=1;

	 /** The customer directory. Customers are stored by their id. */
	std::map<std::string, std::unique_ptr<Customer>>customers;
public:
	enum AccountType
	{
		current=1,
		Savings,
		CD
	};
	Bank();
	Customer* createCustomer();
	 /**
	     * Looks up a customer in the customer directory by its id.
	     *
	     * @param id the customer id
	     * @return a pointer to the customer or nullptr if no customer
	     * with this id exists
	     */
	Customer* lookupCustomer(std::string id)const;
	std::vector<Customer*>allCustomers()const;
	virtual ~Bank();
};

#endif /* BANK_H_ */
