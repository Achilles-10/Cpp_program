#include <iostream>

using namespace std;

long double probability(unsigned field, unsigned picks, unsigned particular);

int main() {
	unsigned total, choice, particular;
	cout << "Enter the total number of choices, the number of picks allowed"
			"\nand the particular number (q to quit):\n";
	while ((cin >> total >> choice >> particular) && choice <= total) {
		cout << "You have one chance in " << probability(total, choice, particular);
		cout << " of winning.\n";
		cout << "Next three numbers (q to quit): ";
	}
	cout << "Bye!\n";

	return 0;
}

long double probability(unsigned field, unsigned picks, unsigned particular) {
	long double result = 1.0, n;
	unsigned p;

	for (n = field, p = picks; p > 0; n--, p--)
		result *= n / p;
	result *= particular;
	return result;
}
