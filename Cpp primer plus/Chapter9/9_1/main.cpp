#include <iostream>
#include "golf.h"

int main() {
	using namespace std;
	golf g;
	cout << "Use setgolf(g,\"Achilles Zhang\",60):\n";
	setgolf(g, "Achilles Zhang", 60);
	showgolf(g);
	cout << "Use handicap(g,70)\n";
	handicap(g, 70);
	showgolf(g);
	golf g_arr[3];
	int i = 0;
	cout << "Now use setgolf(golf & g) in a loop:\n";
	while (i < 3 && setgolf(g_arr[i++]));
	for (int j = 0; j < i-1; ++j){
		cout << "#" << j+1 << ":\n";
		showgolf(g_arr[j]);
	}
	cout << "Done!" << endl;

	return 0;
}