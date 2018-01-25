#include <iostream>

using namespace std;

const int ArSize = 10;

void strcount(const string);

int main() {
	string input;
	char next;

	cout << "Enter a line:\n";
	getline(cin, input);
	while (input != "") {
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;

}

void strcount(const string str) {
	static int total = 0;
	int count = 0, i = 0;

	cout << "\"" << str << "\" contains ";
	while (str[i++])
		count++;
	total+=count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}