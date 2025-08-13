/*
 * Customer.h
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <Poco/Data/Date.h>
#include <iomanip>
#include <exception>
#include "Bank.h"
class Account;
class Customer
{
private:
	const unsigned int number;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	std::map<std::string,std::unique_ptr<Account>>accounts;
public:
	Customer(unsigned int number);
	unsigned int getNumber()const;
	/**
	     * Returns the customer id. The id is the customer number
	     * left padded with zeros until the length is 10. Example:
	     * if the customer number is 1234, the id is "0000001234".
	     */
	std::string getId()const;
	Customer* setPersonalData(std::string lastName, std::string firstName,Poco::Data::Date dateOfBirth);
	const Poco::Data::Date& getDateofBirth()const;
	const std::string& getFirstName()const;
	const std::string& getLastName()const;
   Account* createAccount(Bank::AccountType type);
   std::vector<Account*>allAccounts()const;
   Account* lookupAccount(std::string id)const;
   /**
     * Delete the account with the given id if its balance is 0.
     *
     * Implementation hint: in order to avoid searching through
     * the accounts twice, the implementation must use
     * an iterator for searching and erasing the account.
     *
     * @param id the account id
     * @throws invalid_argument if an account with the given id
     * does not exist
     * @throws logic_error if the balance of the account is not 0
     */
   void deleteAccount(std::string id);

	virtual ~Customer();
};
std::ostream& operator<<(std::ostream& out, const Customer& customer);
#endif /* CUSTOMER_H_ */
