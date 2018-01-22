#include <iostream>

using namespace std;

double mean(double, double);

int main() {
	cout << "Please enter two numbers(0 to quit): ";
	double a, b, result;
	while (cin >> a >> b && a && b) {
		result = mean(a, b);
		cout << "Harmonic Mean of " << a << " and " << b << " : " << result << endl;
		cout << "Please enter two numbers(0 to quit): ";
	}
	cout << "Bye!\n";

	return 0;
}

double mean(double a, double b) {
	return 2 * a * b / (a + b);
}