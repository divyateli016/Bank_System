/*
 * CDAccount.h
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#ifndef CDACCOUNT_H_
#define CDACCOUNT_H_
#include "Account.h"
class Customer;
class CDAccount:public Account
{
public:
	/**
	     * Initializes a new account.
	     *
	     * @param customer the customer for which an account is to be created
	     */

	CDAccount(Customer* customer);
	/**
	     * Sets the field "accountType" of the object to "CD".
	     *
	     * @return the object for method invocation chaining
	     */
	    Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const;

	virtual ~CDAccount();
};

#endif /* CDACCOUNT_H_ */
