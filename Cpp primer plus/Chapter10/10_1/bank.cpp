//
// Created by 10299 on 2018/1/25.
//

#include <iostream>
#include "bank.h"

BankAccount::BankAccount() {}

BankAccount::BankAccount(const std::string &client, const std::string &num, double bal) {
	name = client;
	acctnum = num;
	balance = bal;
}

BankAccount::~BankAccount() {}

void BankAccount::show() const {
	std::cout << "name: " << name << std::endl;
	std::cout << "account number: " << acctnum << std::endl;
	std::cout << "balance: " << balance << std::endl;
}

void BankAccount::deposit(double cash) {
	balance += cash;
}

void BankAccount::withdraw(double cash) {
	while (cash > balance) {
		std::cout << "You do not have enough money.\n"
		          << "Please enter another cash: ";
		std::cin >> cash;
	}
	balance -= cash;
}