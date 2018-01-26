#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char *n, int ci) {
	strcpy(name, n);
	CI = ci;
}

void Plorg::modify(int ci) {
	CI = ci;
}

void Plorg::show() const {
	std::cout << "Name: " << name << std::endl
	          << "CI: " << CI << std::endl;
}