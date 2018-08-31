#ifndef CLASSIC_H
#define CLASSIC_H

#include "cd.h"

class Classic : public Cd {
private:
	char *preview;
public:
	Classic(char *pre, char *s1, char *s2, int n, double x);

	Classic();

	virtual ~Classic();

	virtual void Report() const;

	Classic &operator=(const Classic & c);
};


#endif