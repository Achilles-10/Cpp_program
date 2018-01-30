//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_STONEWT_H
#define CPPLEARN_STONEWT_H

#include <iostream>

class Stonewt {
private:
	enum {
		Lbs_per_stn = 14
	};
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);

	Stonewt(int stn, double lbs);

	Stonewt();

	~Stonewt();

	void show_lbs() const;

	void show_stn() const;

	bool operator<(const Stonewt &t) const;

	bool operator>(const Stonewt &t) const;

	bool operator>=(const Stonewt &t) const;

	bool operator<=(const Stonewt &t) const;

	bool operator!=(const Stonewt &t) const;

	bool operator==(const Stonewt &t) const;
};

#endif //CPPLEARN_STONEWT_H