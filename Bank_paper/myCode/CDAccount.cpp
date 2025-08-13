/*
 * CDAccount.cpp
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */

#include "CDAccount.h"

CDAccount::CDAccount(Customer *customer):Account(customer,Bank::CD)
{
}

Poco::JSON::Object& CDAccount::setAccountType(Poco::JSON::Object &obj) const
{
	obj.set("accountType","CD");
	return obj;

}

CDAccount::~CDAccount()
{
	// TODO Auto-generated destructor stub
}

