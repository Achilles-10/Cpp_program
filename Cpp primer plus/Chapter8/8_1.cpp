#include <iostream>

using namespace std;

const int Limit = 20;

void print(char *str, int x = 0) {
	if (x == 0)
		cout << str << endl;
	else
		for (int i = 0; i < x; ++i)
			print(str);
}

int main() {
	cout << "Please enter a string:\n";
	char *pt = new char[Limit+1];
	cin.getline(pt,Limit);
	cout << "x = 0\n";
	print(pt);
	cout << "x = 4\n";
	print(pt, 4);
	delete[]pt;

	return 0;
}