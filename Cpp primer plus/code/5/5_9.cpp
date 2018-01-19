#include <iostream>

using namespace std;

int main() {
	string words;
	int count = 0;
	cout << "Enter words (to stop, type the word done):\n";
	cin >> words;
	while (words != "done") {
		count++;
		cin >> words;
	}
	cout << "You entered a total of " << count << " words.\n";
	
	return 0;
}
