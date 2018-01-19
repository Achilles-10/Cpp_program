#include <iostream>
#include <array>

using namespace std;
const int ArSize = 16;

int main() {
	array<long double, ArSize> factorials;
	factorials[0] = factorials[1] = 1;
	for (int i = 2; i < ArSize; ++i)
		factorials[i] = i * factorials[i - 1];
	for (int j = 0; j < ArSize; ++j)
		cout << j << "! = " << factorials[j] << endl;

	long double fac = factorials[15];
	for (int k = 16; k < 101; ++k)
		fac *= k;
	cout << "100! = " << fac << endl;

	return 0;
}