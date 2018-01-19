#include <iostream>

using namespace std;
struct car {
	string make;
	int year;
};

int main() {
	int num;
	cout << "How many cars do you with to catalog? ";
	cin >> num;
	cin.get();
	car *p_car = new car[num];
	for (int i = 0; i < num; ++i) {
		cout << "Car #" << i+1 << ":\n";
		cout << "Please enter the make: ";
		getline(cin, (p_car + i)->make);
		cout << "Please enter the year made: ";
		cin >> (p_car + i)->year;
		cin.get();
	}
	cout << "Here is your collection:\n";
	for (int j = 0; j < num; ++j)
		cout << (p_car + j)->year << " " + (p_car + j)->make + "\n";

	return 0;
}