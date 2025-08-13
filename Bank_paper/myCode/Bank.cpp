/*
 * Bank.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#include "Bank.h"
#include "Customer.h"
Bank::Bank()
{
	// TODO Auto-generated constructor stub

}

Customer* Bank::createCustomer()
{
	//unsigned int customernumber = this->nextCustomerNumber;
	//std::map<std::string, std::unique_ptr<Customer>>customers;
	std::unique_ptr<Customer>newcustomer = std::make_unique<Customer>(this->nextCustomerNumber);
	this->nextCustomerNumber++;
	Customer* cusptr = newcustomer.get();
	std::string id = cusptr->getId();
	this->customers.insert(make_pair(id,std::move(newcustomer)));
	return cusptr;
}

Customer* Bank::lookupCustomer(std::string id) const
{
	auto findcutomer = this->customers.find(id);
	if(findcutomer!=customers.end())
	{
		return findcutomer->second.get();
	}
	else
	{
		return nullptr;
	}
}

std::vector<Customer*> Bank::allCustomers() const
{
	std::vector<Customer*>allcustomers;
	for(const auto& cus : customers)
	{
		allcustomers.push_back(cus.second.get());
	}
	return allcustomers;
}

Bank::~Bank()
{
	// TODO Auto-generated destructor stub
}

