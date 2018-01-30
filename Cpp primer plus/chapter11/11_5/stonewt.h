//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_STONEWT_H
#define CPPLEARN_STONEWT_H

#include <iostream>

enum Mode {
	STONE, POUNDS, PDS_FLOAT
};

class Stonewt {
private:
	static const int Lbs_per_stn = 14;
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs, Mode m = POUNDS);

	Stonewt(int stn, double lbs, Mode m = POUNDS);

	Stonewt();

	~Stonewt();

	void set_mode(Mode m = POUNDS);

	Stonewt operator+(const Stonewt &s) const;

	Stonewt operator-(const Stonewt &s) const;

	Stonewt operator*(double n) const;

	friend Stonewt operator*(double n, const Stonewt &s);

	friend std::ostream &operator<<(std::ostream &os, const Stonewt &s);
};

#endif //CPPLEARN_STONEWT_H