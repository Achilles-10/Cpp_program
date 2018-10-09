#include <iostream>
#include <string>

bool isEcho(const std::string &s);

int main() {
	using namespace std;
	string s;
	cout << "Enter a string (quit to quit):\n";
	while (cin >> s && s != "quit") {
		if (isEcho(s)) {
			cout << "Echo!\n";
		}
		else
			cout << "Not Echo!\n";
	}

	return 0;
}

bool isEcho(const std::string &s) {
	auto length = s.size();
	for (int i = 0; i < length / 2; ++i) {
		if (s[i] == s[length-i-1])
			continue;
		else
			return false;
	}
	return true;
}