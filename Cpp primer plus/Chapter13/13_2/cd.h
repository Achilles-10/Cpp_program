#ifndef CD_H
#define CD_H

class Cd {
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd(char *s1, char *s2, int n, double x);

	Cd();

	virtual ~Cd();

	virtual void Report() const;

	Cd &operator=(const Cd &d);
};


#endif
