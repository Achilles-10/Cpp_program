#include <iostream>

using namespace std;
const char *Month[12] = {
		"January", "February", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December"
};

int main() {
	int sale[12], sum = 0;
	cout << "Please input each month's sale volume:\n";
	for (int i = 0; i < 12; ++i) {
		cout << "Sale in " << Month[i] << ": ";
		cin >> sale[i];
		sum += sale[i];
	}
	cout << "This year's sale volume is " << sum;

	return 0;
}