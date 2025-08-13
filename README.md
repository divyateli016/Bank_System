# Bank\_System



Bank Account Management System (C++)

This project implements a simple bank account management system in C++ using object-oriented programming principles such as inheritance, composition, and polymorphism.



The UML diagram above represents the class structure:



Bank – Represents the bank entity.



Customer – Represents a bank customer. Associated with one or more accounts.



Account (Abstract Base Class) – Defines the common interface and destructor for all account types.



CurrentAccount, SavingsAccount, CDAccount – Specific account types derived from Account. Each has its own features and behaviors.



Key OOP Concepts Used

Inheritance: CurrentAccount, SavingsAccount, and CDAccount inherit from the Account base class.



Composition: Bank is associated with Customer, and Customer holds accounts.



Polymorphism: Common operations can be performed on all account types through the Account interface

