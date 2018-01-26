//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_PLORG_H
#define CPPLEARN_PLORG_H

class Plorg {
	char name[20];
	int CI;
public:
	Plorg(const char *name = "Plorga", int ci = 50);

	void modify(int ci);

	void show() const;
};

#endif //CPPLEARN_PLORG_H