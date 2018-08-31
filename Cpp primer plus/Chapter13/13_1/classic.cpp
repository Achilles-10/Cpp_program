#include "classic.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Cd::Cd(char *s1, char *s2, int n, double x) : selections(n), playtime(x) {
	strcpy(performers, s1);
	strcpy(label, s2);
}

Cd::Cd() {
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

void Cd::Report() const {
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Classic::Classic(char *pre, char *s1, char *s2, int n, double x) : Cd(s1, s2, n, x) {
	strcpy(preview, pre);
}

Classic::Classic() {
	preview[0] = '\0';
}

void Classic::Report() const {
	Cd::Report();
	cout << "preview: " << preview << endl;
}