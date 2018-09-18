#include <iostream>
#include <string>
#include <stdexcept>

class My_exception : public std::logic_error {
private:
	double v1;
	double v2;
	std::string funname;
public:
	My_exception(double a, double b, const std::string &f = "none",
	             const std::string &s = "invalid arguments")
			: v1(a), v2(b), funname(f), logic_error(s) {}

	void mesg() const {
		std::cout << "In function: " << funname << ", " << v1 << " and " << v2 << " is "
		          << what();
	}

};


class bad_hmean : public My_exception {
public:
	bad_hmean(double a, double b, const std::string &f = "hmean()",
	          const std::string &s = "invalid arguments\n")
			: My_exception(a, b, f, s) {}
};

class bad_gmean : public My_exception {
public:
	bad_gmean(double a, double b, const std::string &f = "none()",
	          const std::string &s = "invalid arguments\n")
			: My_exception(a, b, f, s) {}

};