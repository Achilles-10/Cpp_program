#include <cmath>
	#include "vect.h"
	
	
	using std::sqrt;
	using std::sin;
	using std::cos;
	using std::atan;
	using std::atan2;
	using std::cout;
	
	const double Rad_to_Deg = 45.0 / atan(1.0);
	
	double Vector::magval() const { return sqrt(x * x + y * y); }
	
	double Vector::angval() const { return (x == 0.0 && y == 0.0) ? 0.0 : atan2(y, x); }
	
	void Vector::set_mag() {
		mag = sqrt(x * x + y * y);
	}
	
	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	
	void Vector::set_x() {
		x = mag * cos(ang);
	}
	
	void Vector::set_y() {
		y = mag * sin(ang);
	}
	
	Vector::Vector() {
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	
	Vector::~Vector() {}
	
	void Vector::rect_mode() {
		mode = RECT;
	}
	
	void Vector::polar_mode() {
		mode = POL;
	}
	
	Vector Vector::operator*(double n) const {
		return Vector(x * n, y * n);
	}
	
	Vector Vector::operator+(const Vector &b) const {
		return Vector(x + b.x, y + b.y);
	}
	
	Vector Vector::operator-(const Vector &b) const {
		return Vector(x - b.x, y - b.y);
	}
	
	Vector Vector::operator-() const {
		return Vector(-x, -y);
	}
	
	Vector operator*(double n, const Vector &a) {
		return a * n;
	}
	
	std::ostream &operator<<(std::ostream &os, const Vector &v) {
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_Deg << ")";
		else
			os << "Vector object mode is invalid";
		return os;
	}