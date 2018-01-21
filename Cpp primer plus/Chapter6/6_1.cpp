#include <iostream>
#include <cctype>

using namespace std;

int main() {
	cout << "Please enter characters(\'@\' to quit):\n";
	char ch;
	while ((ch = cin.get()) != '@') {
		if (isdigit(ch))
			continue;
		else if (islower(ch))
			cout << (char) toupper(ch);
		else if (isupper(ch))
			cout << (char) tolower(ch);
		else
			cout << ch;
	}
	return 0;
}