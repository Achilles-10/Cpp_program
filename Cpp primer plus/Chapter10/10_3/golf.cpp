#include <iostream>
#include "golf.h"

Golf::Golf(const std::string name, int hc) {
	fullname = name;
	handicap = hc;
}


void Golf::setgolf() {
	std::string name;
	int handi;
	std::cout << "Please enter fullname:\n";
	while (!(getline(std::cin, name)))
		std::cout << "Wrong! Please enter again:\n";
	std::cout << "Now enter handicap:\n";
	while (!(std::cin >> handi))
		std::cout << "Wrong! Please enter again:\n";
	std::cin.get();
	*this = Golf(name, handi);
}

void Golf::hanfun(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	std::cout << "Full name: " << fullname << std::endl;
	std::cout << "Handicap: " << handicap << std::endl;
}