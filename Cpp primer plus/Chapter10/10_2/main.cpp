#include <iostream>
#include "person.h"

using namespace std;

int main() {
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	cout << "One:\n";
	one.Show();
	cout << "Two:\n";
	two.FormalShow();
	cout << "Three:\n";
	three.Show();
	cout << "Three(Formal):\n";
	three.FormalShow();

	return 0;
}