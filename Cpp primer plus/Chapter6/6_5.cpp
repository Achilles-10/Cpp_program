#include <iostream>

using namespace std;

int main() {
	double tax = 0.0;
	int tvarp;
	cout << "Please enter your income: ";
	while (cin >> tvarp && tvarp >= 0) {
		if (tvarp < 5001);
		else if (tvarp < 15001)
			tax = (tvarp - 5000) * 0.1;
		else if (tvarp < 35001)
			tax = 10000 * 0.1 + (tvarp - 15000) * 0.15;
		else
			tax = 10000 * 0.1 + 20000 * 0.15 + (tvarp - 35000) * 0.2;
		cout << "Income " << tvarp << "tvarps\n";
		cout << "Taxes: " << tax << "tvarps\n";
		cout << "Please enter your income: ";
	}

	return 0;
}