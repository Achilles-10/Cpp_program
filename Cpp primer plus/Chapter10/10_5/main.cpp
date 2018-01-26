#include <iostream>
#include <cctype>
#include "stack.h"

using namespace std;

int main() {
	Stack stacker;
	double total = 0.0;
	char ch;
	Item cus;
	cout << "Please enter A to add a customer,\n"
	     << "P to delete a customer, T to check total,\n"
	     << "or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n');
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
			case 'A':
			case 'a':
				cout << "Enter customer's name:\n";
				cin.getline(cus.fullname, 34);
				cus.fullname[34] = '\0';
				cout << "Enter customer's payment:\n";
				cin >> cus.payment;
				cin.get();
				if (stacker.isfull())
					cout << "stack already full\n";
				else
					stacker.push(cus);
				break;
			case 'P':
			case 'p':
				if (stacker.isemptey())
					cout << "stacker already empty\n";
				else {
					stacker.pop(cus);
					cout << "customer \"" << cus.fullname << "\" popped\n";
					total += cus.payment;
				}
				break;
			case 'T':
			case 't':
				cout << "Total payment is " << total << endl;
				break;
		}
		cout << "Please enter A to add a customer,\n"
		     << "P to delete a customer, T to check total,\n"
		     << "or Q to quit.\n";
	}
	cout << "Bye\n";

	return 0;
}