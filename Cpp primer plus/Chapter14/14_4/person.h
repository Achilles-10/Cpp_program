#ifndef WORKER_H
#define WORKER_H

#include <string>

using std::string;

class Person {
private:
	string fullname;
protected:
	virtual void Data() const;

	virtual void Get();

public:
	Person(const string &fn = "none") : fullname(fn) {};

	virtual ~Person() = 0;

	virtual void Set() = 0;

	virtual void Show() const = 0;
};

class Gunslinger : virtual public Person {
private:
	double time;
	int scrapes;
protected:
	void Data() const;

	void Get();

public:
	Gunslinger() : Person(), scrapes(0), time(0) {}

	Gunslinger(const string &fn, double t, int scr)
			: Person(fn), time(t), scrapes(scr) {}

	~Gunslinger() {}

	double Draw() const { return time; }

	void Show() const;

	void Set();
};


class PokerPlayer : virtual public Person {
private:
	int card;
protected:
	void Data() const;

	void Get();
public:
	PokerPlayer() : Person(), card(0) {}

	PokerPlayer(const string &fn, int val)
			: Person(fn), card(val) {}

	~PokerPlayer() {}

	int Draw() const { return card; }

	void Show() const;

	void Set();
};

class BadDude : public Gunslinger, public PokerPlayer {
protected:
	void Data() const;

	void Get();
public:
	BadDude() : Person(), Gunslinger(), PokerPlayer() {}

	BadDude(const string &fn, double t, int scr, int val)
			: Person(fn), Gunslinger(fn, t, scr), PokerPlayer(fn, val) {}

	~BadDude() {}

	double Gdraw() const { return Gunslinger::Draw(); }

	int Cdraw() const { return PokerPlayer::Draw(); }

	void Show() const;

	void Set();
};


#endif