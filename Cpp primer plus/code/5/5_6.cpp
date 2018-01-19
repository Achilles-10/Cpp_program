#include <iostream>

using namespace std;
const char *Month[12] = {
		"January", "February", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December"
};
const char *Year[3] = {"first", "second", "third"};

int main() {
	int sale[3][12], sum_all = 0;
	cout << "Please input each month's sale volume in three years:\n";
	for (int j = 0; j < 3; ++j) {
		int sum_year = 0;
		cout << "Now enter the " << Year[j] << " years':\n";
		for (int i = 0; i < 12; ++i) {
			cout << "Sale in " << Month[i] << ": ";
			cin >> sale[j][i];
			sum_year += sale[j][i];
		}
		cout << "This year's sale volume is " << sum_year << endl << endl;
		sum_all += sum_year;
	}
	cout << "Three years' sale volume is " << sum_all << endl;
	
	return 0;
}