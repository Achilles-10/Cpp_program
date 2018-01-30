#include "complex.h"

complex::complex(double a, double b) {
	real = a;
	imaginary = b;
}

complex complex::operator+(const complex &b) const {
	complex sum;
	sum.real = real + b.real;
	sum.imaginary = imaginary + b.imaginary;
	return sum;
}

complex complex::operator-(const complex &b) const {
	complex diff;
	diff.real = real - b.real;
	diff.imaginary = imaginary - b.imaginary;
	return diff;
}

complex complex::operator*(double n) const {
	return complex(n * real, n * imaginary);
}

complex complex::operator*(const complex &b) const {
	complex mul;
	mul.real = real * b.real - imaginary * b.imaginary;
	mul.imaginary = real * b.imaginary + imaginary * b.real;
	return mul;
}

complex operator*(double n, const complex &a) {
	return a * n;
}

complex complex::operator~() const {
	return complex(real, -imaginary);
}

std::ostream &operator<<(std::ostream &os, const complex &c) {
	os << "(" << c.real << "," << c.imaginary << "i)";
	return os;
}

std::istream &operator>>(std::istream &is, complex &c) {
	std::cout << "real: ";
	is >> c.real;
	std::cout << "imaginary: ";
	is >> c.imaginary;
	return is;
}