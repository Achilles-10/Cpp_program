#include "port.h"
#include <iostream>

int main()
{
	Port p1;
	Port p2("Tsingtao", "Beer", 30);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	Port p3 = p2;
	p3.show();
	p3 += 3;
	p3.show();

	VintagePort vp1("Harbin", 50, "hb", 1992);
	vp1.show();
	VintagePort vp2;
	vp2.show();
	vp1 -= 3;
	vp2 = vp1;
	vp2.show();

	return 0;
}