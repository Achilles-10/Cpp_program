//
// Created by 10299 on 2018/1/25.
//
#include <iostream>
#include "golf.h"
#include <cstring>

void setgolf(golf &g, const char *name, int hc) {
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf &g) {
	std::cout << "Please enter fullname:\n";
	std::cin.get(g.fullname, Len);
	if (!std::cin)
		return 0;
	else {
		std::cout << "Now enter handicap:\n";
		std::cin >> g.handicap;
		std::cin.get();
		return 1;
	}
}

void handicap(golf &g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf &g) {
	std::cout << "Full name: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}
