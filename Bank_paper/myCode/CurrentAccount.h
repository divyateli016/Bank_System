/*
 * CurrentAccount.h
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#ifndef CURRENTACCOUNT_H_
#define CURRENTACCOUNT_H_
#include "Account.h"
class Customer;
class CurrentAccount:public Account
{
public:
	CurrentAccount(Customer* customer);
	/**
	     * Sets the field "accountType" of the object to "Current".
	     *
	     * @return the object for method invocation chaining
	     */
	    Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const;

	virtual ~CurrentAccount();
};

#endif /* CURRENTACCOUNT_H_ */
