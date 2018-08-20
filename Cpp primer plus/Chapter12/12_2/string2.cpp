#include "string2.h"
#include <iostream>
#include <cstring>
#include <cctype>

using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}

String::String() {
	len = 0;
	str = nullptr;
	num_strings++;
}

String::String(const char *s) {
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}

String::String(const String &st) {
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_strings++;
}

String::~String() {
	delete[] str;
	num_strings--;
}

int String::has(const char c) const {
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (str[i] == c)
			count++;
	return count;
}

void String::StringLow() {
	for (int i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
}

void String::StringUp() {
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
}

String &String::operator=(const char *s) {
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

String &String::operator=(const String &st) {
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

String &String::operator+(const char *s) const {
	String *temp = new String;
	temp->len = len + strlen(s);
	temp->str = new char[temp->len + 1];
	strcpy(temp->str, str);
	strcat(temp->str, s);
	return *temp;
}

String &String::operator+(const String &st) const {
	String *temp = new String;
	temp->len = len + st.len;
	temp->str = new char[temp->len + 1];
	strcpy(temp->str, str);
	strcat(temp->str, st.str);
	return *temp;
}

char &String::operator[](int i) {
	return str[i];
}

const char &String::operator[](int i) const {
	return str[i];
}

String &operator+(const char *s, const String &st) {
	String *temp = new String;
	temp->len = st.len + strlen(s);
	temp->str = new char[temp->len + 1];
	strcpy(temp->str, s);
	strcat(temp->str, st.str);
	return *temp;
}

bool operator<(const String &st1, const String &st2) {
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2) {
	return st2 < st1;
}

bool operator==(const String &st1, const String &st2) {
	return (strcmp(st1.str, st2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st) {
	os << st.str;
	return os;
}

istream &operator>>(istream &is, String &st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}