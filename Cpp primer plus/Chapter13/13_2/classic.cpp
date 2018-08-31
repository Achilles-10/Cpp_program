#include "classic.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Cd::Cd(char *s1, char *s2, int n, double x) : selections(n), playtime(x) {
	performers = new char[strlen(s1) + 1];
	label =new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
}

Cd::Cd() {
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {
	delete[] performers;
	delete[] label;
}

void Cd::Report() const {
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Cd &Cd::operator=(const Cd &d) {
	if (this == &d)
		return *this;
	selections = d.selections;
	playtime = d.playtime;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label=new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	return *this;
}

Classic::Classic(char *pre, char *s1, char *s2, int n, double x) : Cd(s1, s2, n, x) {
	preview = new char[strlen(pre) + 1];
	strcpy(preview, pre);
}

Classic::Classic() {
	preview = nullptr;
}

void Classic::Report() const {
	Cd::Report();
	cout << "preview: " << preview << endl;
}

Classic::~Classic() {
	delete[] preview;
}

Classic &Classic::operator=(const Classic &c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete [] preview;
	preview = new char [strlen(c.preview)+1];
	strcpy(preview,c.preview);

	return *this;
}