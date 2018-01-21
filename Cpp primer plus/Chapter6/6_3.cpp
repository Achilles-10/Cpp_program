#include <iostream>

using namespace std;

void menu();

int main() {
	cout << "Please enter one of the following choices:\n";
	menu();
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case 'c':
				cout << "Lions are carnivores\n";
				break;
			case 'p':
				cout << "You are destined to be a great pianist\n";
				break;
			case 't':
				cout << "A maple is a tree\n";
				break;
			case 'g':
				cout << "NBA2k18 is my favorite computer game\n";
				break;
			default:
				cout << "Please enter a c, p, t, or g: ";
				continue;
		}
		return 0;
	}
}

void menu() {
	cout << "c) carnivore\tp) pianist\n";
	cout << "t) tree     \tg) game\n";
}