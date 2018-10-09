#include <iostream>
#include <string>
#include <cctype>

bool isEcho(const std::string &s);

void newString(std::string &s);

int main() {
	using namespace std;
	string s;
	cout << "Enter a string (quit to quit):\n";
	while (getline(cin, s) && s != "quit") {
		newString(s);
		if (isEcho(s)) {
			cout << "Echo!\n";
		}
		else
			cout << "Not Echo!\n";
	}
	return 0;
}

void newString(std::string &s) {
	int length = s.size();
	std::string temp;
	for (int i = 0; i < length; ++i) {
		if (isalpha(s[i])) {
			temp += s[i];
		}
	}
	s=temp;
	length = s.size();
	for (int j = 0; j < length; ++j) {
		s[j] = tolower(s[j]);
	}
}

bool isEcho(const std::string &s) {
	auto length = s.size();
	for (int i = 0; i < length / 2; ++i) {
		if (s[i] == s[length - i - 1])
			continue;
		else
			return false;
	}
	return true;
}