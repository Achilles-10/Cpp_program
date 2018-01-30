#include "stonewt.h"

Stonewt::Stonewt(double lbs, Mode m) {
	pounds = lbs;
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	mode = m;
}

Stonewt::Stonewt(int stn, double lbs, Mode m) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = m;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
	mode = POUNDS;
}

Stonewt::~Stonewt() {
}

void Stonewt::set_mode(Mode m) {
	mode = m;
}

Stonewt Stonewt::operator+(const Stonewt &s) const {
	Stonewt sum;
	sum.pounds = pounds + s.pounds;
	sum.stone = int(sum.pounds) / Lbs_per_stn;
	sum.pds_left = int(sum.pounds) % Lbs_per_stn + sum.pounds - int(sum.pounds);
	sum.mode = POUNDS;
	return sum;
}

Stonewt Stonewt::operator-(const Stonewt &s) const {
	Stonewt diff;
	if (pounds < s.pounds) {
		std::cout << "Wrong, return a default Stonewt\n";
		return diff;
	}
	diff.pounds = pounds - s.pounds;
	diff.stone = int(diff.pounds) / Lbs_per_stn;
	diff.pds_left = int(diff.pounds) % Lbs_per_stn + diff.pounds - int(diff.pounds);
	diff.mode = POUNDS;
	return diff;
}

Stonewt Stonewt::operator*(double n) const {
	return Stonewt(n * pounds);
}

Stonewt operator*(double n, const Stonewt &s) {
	return s * n;
}

std::ostream &operator<<(std::ostream &os, const Stonewt &s) {
	if (s.mode == POUNDS)
		os << int(s.pounds) << " pounds";
	else if (s.mode == STONE)
		os << s.stone << " stone, " << s.pds_left << " pounds";
	else if (s.mode == PDS_FLOAT)
		os << s.pounds << " pounds";
}