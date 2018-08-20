#include "12_1.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

Cow::Cow() {
	name[0] = '\0';
	hobby = new char[41];
	strcpy(hobby, "\0");
	weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
	strcpy(name, nm);
	hobby = new char[41];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow &c) {
	strcpy(name, c.name);
	hobby = new char[41];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow() {
	delete[]hobby;
}

Cow &Cow::operator=(const Cow &c) {
	if (this == &c)
		return *this;
	strcpy(name, c.name);
	delete[] hobby;
	hobby = new char[41];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	cout << "Name: " << name << endl;
	cout << "Hobby: " << hobby << "    " << "Weight: " << weight << endl;
}