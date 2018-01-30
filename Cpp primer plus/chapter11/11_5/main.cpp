#include <iostream>
#include "stonewt.h"

int main() {
	using namespace std;
	Stonewt stone1(100);
	Stonewt stone2(2, 11);
	Stonewt stone3 = stone1 + stone2;
	stone1.set_mode(STONE);
	stone2.set_mode(POUNDS);
	cout << "stone1(in stone):\n" << stone1 << endl;
	cout << "stone1(in pounds):\n" << stone2 << endl;
	cout << "stone3 = stone1 + stone2:\n" << stone3 << endl;
	cout << "stone1 * 1.17 = " << stone1 * 1.17 << endl;
	cout << "stone1 - stone2 = " << stone1 - stone2 << endl;

	return 0;
}