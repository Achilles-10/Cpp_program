#include <iostream>

using namespace std;

long double factorial(unsigned);

int main() {
	cout << "Please enter a number (q to quit): ";
	unsigned a;
	while (cin >> a) {
		cout << a << "\'s factorial is " << factorial(a) << endl;
		cout << "Next number (q to quit): ";
	}
	cout << "Bye!\n";

	return 0;
}

long double factorial(unsigned n) {
	if (n > 1)
		return n * factorial(n - 1);
	return 1;
}