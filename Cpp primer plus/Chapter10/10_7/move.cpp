#include <iostream>
#include "plorg.h"

using namespace std;

int main() {
	Plorg plorg1;
	cout << "plorg1:\n";
	plorg1.show();
	Plorg plorg2("Achilles",100);
	cout << "plorg2:\n";
	plorg2.show();
	cout << "reset plorg2's CI to 90\n";
	plorg2.modify(90);
	plorg2.show();

	return 0;
}