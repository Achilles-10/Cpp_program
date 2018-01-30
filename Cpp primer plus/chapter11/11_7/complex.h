//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_COMPLEX_H
#define CPPLEARN_COMPLEX_H

#include <iostream>

class complex {
private:
	double real;
	double imaginary;
public:
	complex(double a = 0.0, double b = 0.0);

	~complex() {}

	complex operator+(const complex &b) const;

	complex operator-(const complex &b) const;

	complex operator*(const complex &b) const;

	complex operator*(double n) const;

	complex operator~() const;

	friend complex operator*(double n, const complex &a);

	friend std::ostream &operator<<(std::ostream &os, const complex &c);

	friend std::istream &operator>>(std::istream &is, complex &c);
};

#endif //CPPLEARN_COMPLEX_H