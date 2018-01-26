#include <iostream>
#include "golf.h"

using namespace std;

int main() {
	Golf g1;
	Golf g2("Achilles", 1999);
	Golf g3;
	g3.setgolf();
	cout << "g1:\n";
	g1.showgolf();
	cout << "g2:\n";
	g2.showgolf();
	cout << "g3:\n";
	g3.showgolf();

	return 0;
}