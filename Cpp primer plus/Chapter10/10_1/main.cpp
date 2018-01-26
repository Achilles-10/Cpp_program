#include <iostream>
#include "bank.h"

using namespace std;

int main() {
	BankAccount account("Achilles", "10299", 1000);
	account.show();
	account.deposit(2000);
	cout << "After deposit $2000\n";
	account.show();
	account.withdraw(4000);
	cout << "After withdraw some money.\n";
	account.show();

	return 0;
}