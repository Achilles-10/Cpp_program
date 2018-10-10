#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>

using namespace std;
const int NUM = 26;

void getWordList(const string &filename, vector<string> &wordlist);

int main() {
	srand(time(NULL));
	vector<string> wordlist;
	string filename;
	cout << "Please enter file name:\n";
	cin >> filename;
	getWordList(filename, wordlist);
	int num = wordlist.size();
	cout << num << " words in words.txt" << endl;
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
		     << " letters, and you guess\n"
		     << "one letter at a time. You get " << guesses
		     << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
			    || attempt.find(letter) != string::npos) {
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else {
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";

	return 0;

}


void getWordList(const string &filename, vector<string> &wordlist) {
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "fail to open file: " << filename << endl;
		exit(EXIT_FAILURE);
	}
	string word;
	while (fin >> word) {
		wordlist.push_back(word);
	}
}