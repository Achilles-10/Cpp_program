#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string words;
	int vowel = 0, consonant = 0, other = 0;
	cout << "Enter words (q to quit):\n";
	while (cin >> words && words != "q") {
		if (!isalpha(words[0]))
			other++;
		else
			switch (words[0]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowel++;
					break;
				default:
					consonant++;
			}
	}
	cout << vowel <<" words beginning with vowels\n";
	cout << consonant << " words beginning with consonants\n";
	cout << other << " others\n";

	return 0;
}