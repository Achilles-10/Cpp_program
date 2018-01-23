#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char *str;
	int ct;
};

void set(stringy &, const char *);

void show(const stringy &str, int n = 1) {
	for (int i = 0; i < n; ++i) {
		cout << "string: " << str.str << endl;
		cout << "length: " << str.ct << endl;
	}
}

void show(const char *str, int n = 1) {
	for (int i = 0; i < n; ++i)
		cout << str << endl;
}

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy &beany, const char *str) {
	beany.ct = strlen(str);
	beany.str = new char[beany.ct];
	strcpy(beany.str,str);
}