#include "emp.h"

using std::cout;
using std::cin;
using std::endl;

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j)
		: fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}


void abstr_emp::ShowAll() const {
	cout << "Name: " << lname << ", " << fname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll() {
	cout << "Enter first name: ";
	getline(cin, fname);
	cout << "Enter last name: ";
	getline(cin, lname);
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
	os << "First name: " << e.fname << endl;
	os << "Last name: " << e.lname << endl;
	return os;
}

employee::employee() : abstr_emp() {}

employee::employee(const string &fn, const string &ln, const string &j)
		: abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
	cout << "Category: employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll() {
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const string &fn, const string &ln, const string &j, int ico)
		: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico)
		: abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m) : abstr_emp(m) {
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const {
	cout << "Category: manager\n";
	abstr_emp::ShowAll();
	cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll() {
	abstr_emp::SetAll();
	cout << "Enter in charge of: ";
	cin >> inchargeof;
}

fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const string &fn, const string &ln, const string &j, const string &rpo)
		: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const string &rpo)
		: abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &f) : abstr_emp(f) {
	reportsto = f.reportsto;
}

void fink::ShowAll() const {
	cout << "Category: fink\n";
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll() {
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	getline(cin, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const string &fn, const string &ln,
                   const string &j, int ico, const string &rpo)
		: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp &e, int ico, const string &rpo)
		: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager &m, const string &rpo)
		: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink &hf) : abstr_emp(hf), manager(hf), fink(hf) {}

void highfink::ShowAll() const {
	cout << "Category: highfink\n";
	abstr_emp::ShowAll();
	cout << "In charge of: " << manager::Inchargeof() << endl;
	cout << "Reportsto: " << fink::Reportsto() << endl;
}

void highfink::SetAll() {
	abstr_emp::SetAll();
	cout << "Enter in charge of: ";
	cin >> manager::Inchargeof();
	cin.get();
	cout << "Enter reportsto: ";
	getline(cin, fink::Reportsto());
}
