#include <iostream>

using namespace std;

int main() {
	int min,max,sum=0;
	cout << "Enter two numbers successively: ";
	cin >> min >> max;
	for (int i = min; i <= max; ++i)
		sum+=i;
	cout << "Sum: " << sum << endl;

	return 0;
}