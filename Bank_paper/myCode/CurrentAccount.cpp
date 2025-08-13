/*
 * CurrentAccount.cpp
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(Customer *customer):Account(customer,Bank::current)
{
}

Poco::JSON::Object& CurrentAccount::setAccountType(
		Poco::JSON::Object &obj) const
{
	return obj.set("accountType","current");
}

CurrentAccount::~CurrentAccount()
{
	// TODO Auto-generated destructor stub
}

