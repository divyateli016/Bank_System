/*
 * Customer.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#include "Customer.h"
#include "Bank.h"
#include "Account.h"
#include "CDAccount.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

Customer::Customer(unsigned int number):number(number)
{
}

unsigned int Customer::getNumber() const
{
	return this->number;
}

std::string Customer::getId() const
{
	std::ostringstream oss;
	oss<<std::setw(10)<<std::setfill('0')<<this->getNumber();
	return oss.str();
}

Customer* Customer::setPersonalData(std::string lastName, std::string firstName,
		Poco::Data::Date dateOfBirth)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
	return this;
}

const Poco::Data::Date& Customer::getDateofBirth() const
{
	return this->dateOfBirth;
}

const std::string& Customer::getFirstName() const
{
	return this->firstName;
}

const std::string& Customer::getLastName() const
{
	return lastName;
}

std::vector<Account*> Customer::allAccounts() const
{
	std::vector<Account*>allacc;
	for(auto const& acc : accounts)
	{
		allacc.push_back(acc.second.get());
	}
return allacc;
}

Account* Customer::lookupAccount(std::string id) const
{
	auto findacc = accounts.find(id);
	if(findacc == accounts.end())
	{
		throw std::invalid_argument("Account with given ID is not present");
	}
	return findacc->second.get();
}

void Customer::deleteAccount(std::string id)
{
	auto findacc = accounts.find(id);
	if(findacc==accounts.end())
	{
		throw std::invalid_argument("Given id does not exist");
	}
	else if(findacc!=accounts.end())
	{
		if(findacc->second->getBalance()==0)
		{
			accounts.erase(findacc);
		}
		else
		{
			throw std::logic_error("Balance is not 0");
		}
	}




}

std::ostream& operator <<(std::ostream &out, const Customer &customer)
{
	Poco::Data::Date dob = customer.getDateofBirth();
	out<<customer.getId()<<":"<<customer.getLastName()<<","<<" "<<customer.getFirstName()<<
	" "<<dob.day()<<"."<<dob.month()<<"."<<dob.year();
	return out;
}

Customer::~Customer()
{
	// TODO Auto-generated destructor stub
}

Account* Customer::createAccount(Bank::AccountType type)
{
	std::unique_ptr<Account>account = nullptr;
	if(type == Bank::CD)
	{
		account = std::make_unique<CDAccount>(this);
	}
	else if(type == Bank::current)
	{
		account = std::make_unique<CurrentAccount>(this);
	}
	else if(type == Bank::Savings)
	{
		account = std::make_unique<SavingsAccount>(this);
	}
	Account *acc = account.get();
	std::string id = account.get()->getId();
	accounts[id]=std::move(account);
	return acc;
}
