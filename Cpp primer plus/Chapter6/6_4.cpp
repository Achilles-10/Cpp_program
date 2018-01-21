#include <iostream>

using namespace std;

const int nMember = 3;

struct bop {
	string fullname;
	string title;
	string bopname;
	int preference; // 0 = fullname, 1 = title, 2 = bopname
} member[nMember] = {
		{"Kobe Bryant",    "MVP",          "Black Mamba", 0},
		{"Micheal Jordan", "The greatest", "The air",     1},
		{"LeBorn James",   "All around",   "King",        2}
}; //just for fun, you can customize it yourself

void menu();

int main() {
	menu();
	char ch;
	cout << "Enter your choice: ";
	while (cin >> ch) {
		switch (ch) {
			case 'a':
				for (int i = 0; i < nMember; ++i)
					cout << member[i].fullname << endl;
				break;
			case 'b':
				for (int j = 0; j < nMember; ++j)
					cout << member[j].title << endl;
				break;
			case 'c':
				for (int k = 0; k < nMember; ++k)
					cout << member[k].bopname << endl;
				break;
			case 'd':
				for (int l = 0; l < nMember; ++l)
					if (0 == member[l].preference)
						cout << member[l].fullname << endl;
					else if (1 == member[l].preference)
						cout << member[l].title << endl;
					else
						cout << member[l].bopname << endl;
				break;
			case 'q':
				cout << "Bye!\n";
				return 0;
			default:
				cout << "Pleases enter a a, b, c, d, or q: ";
				continue;
		}
		cout << "Next choice: ";
	}

	return 0;
}

void menu() {
	cout << "Benevolent Order of Programmers Report\n";
	cout << "a. display by name   \tb. display by title\n";
	cout << "c. display by bopname\td. display by preference\n";
	cout << "q. quit\n";
}