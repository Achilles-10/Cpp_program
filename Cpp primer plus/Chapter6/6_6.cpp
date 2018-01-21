#include <iostream>

using namespace std;

struct patron {
	string name;
	double donation;
};

int main() {
	int num, flag = 0;
	cout << "Please enter the number of donors: ";
	cin >> num;
	patron *donors = new patron[num];
	cout << "Now enter their name and donation:\n";
	for (int i = 0; i < num; ++i)
		cin >> donors[i].name >> donors[i].donation;
	cout << "Grand Patrons:\n";
	for (int j = 0; j < num; ++j)
		if (donors[j].donation > 10000) {
			cout << donors[j].name << ": " << donors[j].donation << endl;
			flag = 1;
		}
	if (0 == flag)
		cout << "none!\n";
	flag = 0;
	cout << "Patrons:\n";
	for (int k = 0; k < num; ++k)
		if (donors[k].donation <= 10000) {
			cout << donors[k].name << ": " << donors[k].donation << endl;
			flag = 1;
		}
	if (0 == flag)
		cout << "none!\n";

	return 0;
}