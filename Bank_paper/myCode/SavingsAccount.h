/*
 * SavingsAccount.h
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_
#include "Account.h"
class Customer;
class SavingsAccount:public Account
{
public:
	SavingsAccount(Customer* customer);
	/**
	     * Sets the field "accountType" of the object to "Current".
	     *
	     * @return the object for method invocation chaining
	     */
	    Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const;

	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_H_ */
