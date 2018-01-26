#include <iostream>
#include "golf.h"

Golf::Golf(const std::string name, int hc) {
	fullname = name;
	handicap = hc;
}


const Golf &Golf::setgolf(const Golf &g) {
	fullname = g.fullname;
	handicap = g.handicap;
	return *this;
}

void Golf::hanfun(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	std::cout << "Full name: " << fullname << std::endl;
	std::cout << "Handicap: " << handicap << std::endl;
}