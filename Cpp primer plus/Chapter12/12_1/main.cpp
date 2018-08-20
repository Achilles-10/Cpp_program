#include "12_1.h"
#include <iostream>

int main() {
	Cow blank;
	Cow Bob("Bob", "Dancing", 72.4);
	Cow Bob1(Bob);
	Cow Bob2 = Bob;
	Bob.ShowCow();
	Cow Achilles("Achilles", "B-Ball", 69);
	Achilles.ShowCow();
	blank.ShowCow();

	return 0;
}