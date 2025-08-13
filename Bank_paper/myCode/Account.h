/*
 * Account.h
 *
 *  Created on: Jun 16, 2025
 *      Author: divya
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <Poco/JSON/Object.h>
#include <exception>
#include "Bank.h"

class Customer;
/**
 * Base class for all Accounts. Accounts have an id which is assigned
 * upon creation as follows:
 *
 *  * The first digit indicated the account type
 *    - 1: Current account
 *    - 2: Savings account
 *    - 3: Certificate of deposit account
 *
 *  * The second and third digit represent a counter (sequence number)
 *    for the number of accounts of a given type. Counting starts with 1.
 *
 *  * The remaining 8 digits are the same as the 8 rightmost digits
 *    of the customer id.
 */
class Account
{
private:
	std::string id;
	float balance = 0;
protected:
	/**
	     * Initializes a new account.
	     *
	     * To evaluate the account id, the method uses the type
	     * passed as argument (becomes the leftmost digit). In
	     * addition, it searches through the existing accounts
	     * of the customer in order to find the next free sequence
	     * number for creating an account of the desired type.
	     *
	     * Note that finding the next free sequence number ins't trivial.
	     * Imaging that you have created accounts with ids
	     * 3010000001, 3020000001, 3030000001. Then the second account
	     * is deleted, leaving accounts 3010000001, 3030000001. If you
	     * create a new account of type "3", you'll have to detect that
	     * sequence number "02" is not used and create 3020000001 as
	     * new id.
	     *
	     * @param customer the customer for which an account is to be created
	     * @param type the account type
	     */

	Account(Customer* customer, Bank::AccountType type);
    /**
     * Creates a JSON Object that represents the account data.
     * Fields are "accountType" and "balance", e.g.:
     * {"accountType":"Current","balance":100}
     */
	virtual Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj)const = 0;
public:
	static Bank::AccountType accountType(std::string accountId);
	float getBalance()const;
	std::string getId()const;
	void transact(float amount);
	Poco::JSON::Object::Ptr toJson()const;
	virtual ~Account();
};

#endif /* ACCOUNT_H_ */
