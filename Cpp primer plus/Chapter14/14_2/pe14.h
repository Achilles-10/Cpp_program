#ifndef PE14_H
#define PE14_H

#include <iostream>
#include <valarray>
#include <string>

using std::string;

template<class T1, class T2>
class Pair {
private:
	T1 a;
	T2 b;
public:
	T1 &first();

	T2 &second();

	T1 first() const { return a; }

	T2 second() const { return b; };

	Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}

	Pair(const Pair<T1, T2> &p);

	Pair() {}
};

template<class T1, class T2>
T1 &Pair<T1, T2>::first() {
	return a;
}

template<class T1, class T2>
T2 &Pair<T1, T2>::second() {
	return b;
}

template<class T1, class T2>
Pair<T1, T2>::Pair(const Pair<T1, T2> &p) {
	a = p.a;
	b = p.b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray, private string {
private:
	int years;
public:
	Wine() : string("none"), years(0), PairArray(ArrayInt(0), ArrayInt(0)) {}

	Wine(const char *l, int y, const int yr[], const int bot[]);

	Wine(const char *l, int y);

	~Wine() {};

	const string &Label() const { return (const string &) (*this); }

	void GetBottles();

	void Show() const;

	int sum() const;
};


#endif