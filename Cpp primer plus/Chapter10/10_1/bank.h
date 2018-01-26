//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_BANK_H
#define CPPLEARN_BANK_H

class BankAccount {
	std::string name;
	std::string acctnum;
	double balance;
public:
	BankAccount();

	BankAccount(const std::string &client, const std::string &num, double bal = 0.0);

	~BankAccount();

	void show() const;

	void deposit(double cash);

	void withdraw(double cash);
};


#endif //CPPLEARN_BANK_H
