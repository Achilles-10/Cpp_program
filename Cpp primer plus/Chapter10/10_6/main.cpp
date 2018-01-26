#include <iostream>
#include "move.h"

using namespace std;

int main() {
	Move move1;
	cout << "move1:\n";
	move1.showmove();
	Move move2(3,4);
	cout << "move2:\n";
	move2.showmove();
	Move move3(5,6);
	cout << "move3:\n";
	move3.showmove();
	move1 = move2.add(move3);
	cout << "Add move2 and move3 to move1:\n";
	move1.showmove();
	cout << "reset move1:\n";
	move1.reset();
	move1.showmove();

	return 0;
}