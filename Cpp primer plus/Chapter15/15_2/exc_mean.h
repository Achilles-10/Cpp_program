#include <iostream>

class bad_hmean : public std::exception {
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}

	void what() {
		std::cout << "hmean(" << v1 << ", " << v2 << "): "
		          << "invalid arguments: a = -b\n";
	}
};

class bad_gmean : public std::exception {
public:
	double v1;
	double v2;

	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}

	void what() {
		std::cout << "gmean() arguments should be >= 0\n";
	}
};