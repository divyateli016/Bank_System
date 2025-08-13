/*
 * Account.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#include "Account.h"
#include "Customer.h"
Account::Account(Customer *customer, Bank::AccountType type)
{
	int lowerbyte;
	if(type==Bank::Savings)
	{
		lowerbyte = 2;
	}
	else if(type == Bank::current)
	{
		lowerbyte = 1;
	}
	else if(type == Bank::CD)
	{
		lowerbyte = 3;
	}
	int count = 1;
	for(const auto& acc:customer->allAccounts())
	{
		if(acc->accountType(acc->getId()) == type)
		{
			int seq = std::stoi(acc->getId().substr(1,2));
			if(seq<=count)
			{
				count = seq+1;
			}
		}
	}
	std::ostringstream oss;
	oss<<lowerbyte<<std::setw(2)<<std::setfill('0')<<count<<std::setw(7)<<std::setfill('0')<<customer->getNumber();
	this->id = oss.str();
	this->balance = 0;
}

std::string Account::getId() const
{
	return this->id;
}

Bank::AccountType Account::accountType(std::string accountId)
{
	std::string type_str = accountId.substr(0,1);
	Bank::AccountType btype;
	int type = stoi(type_str);
	if(type == 1)
	{
		btype =  Bank::current;
	}
	else if(type == 2)
	{
		btype =  Bank::Savings;
	}
	else if(type == 3)
	{
		btype =  Bank::CD;
	}
	return btype;
}

void Account::transact(float amount)
{
	if(amount < 0)
	{
		if(this->balance>-amount)
		{
			this->balance = this->balance+amount;//Withdrawl
		}
		else
		{
			std::cout<<"Cannot withdraw the amount with current balance"<<std::endl;
		}
	}
	else
	{
		this->balance+=amount;//Deposite
	}
}

Poco::JSON::Object::Ptr Account::toJson() const
{
	Poco::JSON::Object::Ptr obj= new Poco::JSON::Object;
	setAccountType(*obj);
	obj->set("balance",this->balance);
	return obj;

}

Account::~Account()
{
	// TODO Auto-generated destructor stub
}

float Account::getBalance() const
{
	return this->balance;
}
