/*
 * SavingsAccount.cpp
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(Customer *customer):Account(customer,Bank::Savings)
{
}

Poco::JSON::Object& SavingsAccount::setAccountType(
		Poco::JSON::Object &obj) const
{
	return obj.set("accountType","Savings");
}

SavingsAccount::~SavingsAccount()
{
	// TODO Auto-generated destructor stub
}

