#include <iostream>
#include <cstring>

using namespace std;

int main() {

	const int Size = 20;
	char first[Size], last[Size], name[Size];

	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your last name: ";
	cin >> last;
	strcat(last, ", ");
	strcat(last, first);
	strcpy(name, last);
	cout << "Here\'s the information in a single string: " << name << endl;

	return 0;
}
