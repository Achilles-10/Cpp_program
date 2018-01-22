// use array of pointer

#include <iostream>

using namespace std;

typedef double (*ptf)(double, double);

double add(double, double);

double multiply(double, double);

double calculate(double, double, ptf);

int main() {
	ptf p[2] = {add, multiply};
	cout << "Enter two numbers (q to quit): ";
	double a, b;
	while (cin >> a >> b) {
		cout << a << " + " << b << " = " << calculate(a,b,p[0]) << endl; //add
		cout << a << " * " << b << " = " << calculate(a,b,p[1]) << endl; //multiply
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";

	return 0;
}

double add(double x, double y) {
	return x + y;
}

double multiply(double x, double y) {
	return x * y;
}

double calculate(double x, double y, ptf fun) {
	return fun(x, y);
}
