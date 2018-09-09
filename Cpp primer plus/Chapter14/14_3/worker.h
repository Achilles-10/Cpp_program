#ifndef WORKER_H
#define WORKER_H

#include <string>
using std::string;

class Worker{
private:
	string fullname;
	long id;
public:
	Worker() : fullname("no one"),id(0L){}
	Worker(const string & s,long n):fullname(s),id(n){}
	~Worker(){}
	void Set();
	void Show() const;
};

#endif