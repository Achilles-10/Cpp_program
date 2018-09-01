#include "port.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b) : bottles(b) {
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
}

Port::Port(const Port &p) : bottles(p.bottles) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
}

Port::~Port() {
	delete[] brand;
}

Port &Port::operator=(const Port &p) {
	if (this == &p)
		return *this;
	delete brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port &Port::operator+=(int b) {
	bottles += b;
	return *this;
}

Port &Port::operator-=(int b) {
	bottles -= b;
	return *this;
}

void Port::show() const {
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

ostream &operator<<(ostream &os, const Port &p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort():Port("none","vintage",0),year(0) {
	nickname= new char [5];
	strcpy(nickname,"none");
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y):Port(br,"vintage",b),year(y) {
	nickname = new char [strlen(nn)+1];
	strcpy(nickname,nn);
}

VintagePort::VintagePort(const VintagePort &vp):Port(vp) {
	nickname = new char [strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year = vp.year;
}

VintagePort::~VintagePort() {
	delete [] nickname;
}

void VintagePort::show() const {
	Port::show();
	std::cout << "Nickname: " << nickname << std::endl;
}

VintagePort& VintagePort::operator=(const VintagePort &vp) {
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char [strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year = vp.year;
	return *this;
}

ostream& operator<<(ostream &os, const VintagePort &vp) {
	os << (Port &) vp << ", " << vp.nickname << ", " << vp.year;
	return os;
}