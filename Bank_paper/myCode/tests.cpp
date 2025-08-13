/*
 * tests.cpp
 *
 *  Created on: Jun 17, 2025
 *      Author: divya
 */
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <Poco/JSON/Stringifier.h>

using namespace std;

#include "Bank.h"
#include "Customer.h"
#include "Account.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

/**
 * Initializes a bank with customers with different account
 * types. Can be used as data for various tests.
 */
void setupBank(Bank &bank)
{
	// The following code has been commented out to keep
	// the start project buildable. Remove the comments
	// when you have implemented the required methods.

	Customer *c = bank.createCustomer()->setPersonalData("Angel", "Alice",
			Poco::Data::Date(1991, 1, 1));
	c->createAccount(Bank::AccountType::current)->transact(100);
	c->createAccount(Bank::AccountType::Savings)->transact(500);
	c->createAccount(Bank::AccountType::CD)->transact(1000);
	c->createAccount(Bank::AccountType::CD)->transact(2000);
	c->createAccount(Bank::AccountType::CD)->transact(3000);
	bank.createCustomer()->setPersonalData("Billings", "Bob",
			Poco::Data::Date(1992, 2, 2));
	bank.createCustomer()->setPersonalData("Chase", "Caesar",
			Poco::Data::Date(1993, 3, 3));
}
void bankTests()
{
	/**
	 * Create a bank and initialize it with setupBank.
	 */
	// Add your code here:
	Bank mybank;
	setupBank(mybank);
	/*
	 * (1) Assert that the bank has three customers.
	 */
	// Add your code here:
	std::cout<<mybank.allCustomers().size()<<std::endl;
	assertTrue(mybank.allCustomers().size()==3,"Size is not correct");
	/*
	 * (2) Assert that the customer with id 0000000002 can be looked up.
	 */
	// Add your code here:
	Customer*cus = mybank.lookupCustomer("0000000002");
	assertTrue(cus!=nullptr,"customer cannot be lookedat");
	/*
	 * (3) Assert that there is no customer with id 0000000042.
	 */
	// Add your code here:
	assertTrue(mybank.lookupCustomer("0000000042")==nullptr,"There is a customer with this ID");
}
void customerTests () {
    /*
     * (1) Create a Customer with sample data. Assert that
     * invoking the overloaded left shift operator produces the
     * expected result. (Hint: use a stringstream.)
     */
    // Add your code here:
	Bank bank;
	stringstream ss;
	Customer *c = bank.createCustomer()->setPersonalData("Teli","Divya",Poco::Data::Date(1998,3,16));
	ss<<*c;
	assertTrue(ss.str()=="0000000001:Teli, Divya 16.3.1998","Data is not correct");
}
void accountTests () {
    /**
     * Create a bank and initialize it with setupBank.
     */
    // Add your code here:
	Bank bank;
	setupBank(bank);
	 /*
	     * (1) Lookup Customer 0000000001 (Alice), assert that she is found.
	     */
	    // Add your code here:
	Customer* cus = bank.lookupCustomer("0000000001");
	std::cout<<cus->getFirstName()<<std::endl;
	assertTrue(cus->getFirstName()=="Alice","Alice not found");


    /*
     * (2) Assert that Alice has 5 accounts.
     */
    // Add your code here:
	std::cout<<cus->allAccounts().size()<<std::endl;
	assertTrue(cus->allAccounts().size() == 5,"Number of accounts are wrong");
	/**
	     * (3) Assert that the C++-types of Alice's accounts and the
	     * types derived from the account id (see Account::accountType)
	     * match.
	     */
	    // Add your code here:
	for(const auto&acc : cus->allAccounts())
	{
		Bank::AccountType AlicaccType;
		AlicaccType = acc->accountType(acc->getId());
		int accid = std::stoi(acc->getId().substr(0,1));
		Bank::AccountType derived;
		if(accid==1)
		{
			derived = Bank::current;
		}
		else if(accid == 2)
		{
			derived = Bank::Savings;
		}
		else if(accid==3)
		{
			derived = Bank::CD;
		}
		assertTrue(!(AlicaccType != derived),std::string("IDs do not match"));
	}
		//assertTrue(AlicaccType==derived,"Ids are not same");
		/**
		     * (4) Assert that Alice has 3 accounts of type CD
		     * and that these accounts have the ids "3010000001",
		     * "3020000001" and "3030000001". The check must not
		     * rely on accounts being returned in a specific sequence.
		     *
		     * In order to check this, proceed as follows:
		     *  * Obtain the ids
		     *  * Filter out the CD accounts and count them
		     *  * Out the ids in a set and assert that the set contains
		     *    the expected ids.
		     */
		    // Add your code here:
		int count = 0;
		set<std::string>ids;
		set<std::string>expected = {"3010000001","3020000001","3030000001"};
		for(const auto& acc : cus->allAccounts())
		{
			int id = stoi(acc->getId().substr(0,1));
			std::cout<<acc->getId()<<std::endl;

			if(id==3)
			{
				ids.insert(acc->getId());
				count++;
			}

		}
		//std::cout<<"number of accounts"<<count<<std::endl;
		assertTrue(count == 3,"Alice does not have 3 accounts of type 3");
		assertTrue(ids==expected,"Sets are not same");
		/**
		     * (5) Assert that an attempt to delete account 3040000001
		     * throws an invalid_argument exception.
		     */
		    // Add your code here:
		try
		{
			cus->deleteAccount("3040000001");
			assertTrue(false,"Did not throw the exception");
		}catch(exception&e)
		{
			std::cout<<e.what()<<std::endl;
		}
		 /**
		      * (6) Assert that an attempt to delete account 3020000001
		      * throws a logic_error exception.
		      */
		    // Add your code here:
	    // Add your code here:
			try
			{
				cus->deleteAccount("3020000001");
				assertTrue(false,"Did not throw the exception");
			}catch(exception&e)
			{
				std::cout<<e.what()<<std::endl;
			}



}


void allTests() {
    bankTests();
    customerTests();
    accountTests();
}
