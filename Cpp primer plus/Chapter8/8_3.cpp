#include <iostream>
#include <cctype>

using namespace std;

bool upper(string &);

int main() {
	string str;
	cout << "Enter a string (q to quit): ";
	getline(cin, str);
	while (upper(str)) {
		cout << str << endl;
		cout << "Next string (q to quit): ";
		getline(cin, str);
	}
	cout << "Bye!\n";

	return 0;
}

bool upper(string &str) {
	if (str[0] == 'q')
		return false;
	else {
		int i = 0;
		while (str[i]) {
			str[i] = toupper(str[i]);
			++i;
		}
		return true;
	}
}