//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_GOLF_H
#define CPPLEARN_GOLF_H

class Golf {
	std::string fullname;
	int handicap;
public:
	Golf() {fullname = "Nobody",handicap = 0;}

	Golf(const std::string name, int hc);

	void setgolf();

	void hanfun(int hc);

	void showgolf() const;
};

#endif //CPPLEARN_GOLF_H