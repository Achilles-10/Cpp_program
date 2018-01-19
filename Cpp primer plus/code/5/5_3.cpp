#include <iostream>

using namespace std;

int main() {
	int num;
	long sum = 0;
	cout << "Please enter a series of number(0 to quit):\n";
	cin >> num;
	while (num) {
		sum += num;
		cout << "Sum by now is " << sum << endl;
		cin >> num;
	}
	cout << "Bye!\n";
	return 0;
}