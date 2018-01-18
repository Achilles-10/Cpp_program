#include <iostream>

using namespace std;

int main() {

	string first,last,name;

	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your last name: ";
	cin >> last;
	name = last + ", " + first;
	cout << "Here\'s the information in a single string: " << name << endl;

	return 0;
}
