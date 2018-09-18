#include <iostream>
#include <string>
#include <stdexcept>

class bad_hmean : public std::logic_error {
public:
	bad_hmean(const std::string &s = "hmean() invalid arguments: a = -b\n")
			: logic_error(s) {}
};

class bad_gmean : public std::logic_error {
public:
	bad_gmean(const std::string &s = "gmean() arguments should be >= 0\n")
			: logic_error(s) {}

};