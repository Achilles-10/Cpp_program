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

	Pair(const Pair<T1,T2> & p);

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
	a=p.a;
	b=p.b;
}


class Wine {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	string label;
	int years;
	PairArray pair;
public:
	Wine() : label("none"),years(0),pair(ArrayInt(0),ArrayInt(0)) {}

	Wine(const char *l, int y, const int yr[], const int bot[]);

	Wine(const char *l, int y);

	Wine(const Wine& w);

	~Wine() {};

	const string & Label() const { return label;}

	void GetBottles();

	void Show() const;

	int sum() const ;
};


#endif