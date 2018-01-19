#include <iostream>
#include <cstring>

using namespace std;
const int Size = 20;

int main() {
	char words[Size];
	int count = 0;
	cout << "Enter words (to stop, type the word done):\n";
	cin >> words;
	while (strcmp(words, "done")) {
		count++;
		cin >> words;
	}
	cout << "You entered a total of " << count << " words.\n";

	return 0;
}
