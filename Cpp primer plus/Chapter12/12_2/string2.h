#ifndef STRING_2_H
#define STRING_2_H

#include <iostream>

using std::ostream;
using std::istream;

class String {
private:
	char *str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String();

	String(const char *);

	String(const String &);

	~String();

	int length() const { return len; }

	int has(const char) const;

	void StringLow();

	void StringUp();

	String &operator=(const String &);

	String &operator=(const char *);

	String &operator+(const String &) const;

	String &operator+(const char *) const;

	char &operator[](int i);

	const char &operator[](int i) const;

	friend String &operator+(const char *, const String &);

	friend bool operator<(const String &, const String &);

	friend bool operator>(const String &, const String &);

	friend bool operator==(const String &, const String &);

	friend ostream &operator<<(ostream &, const String &);

	friend istream &operator>>(istream &, String &);

	static int HowMany();

};


#endif