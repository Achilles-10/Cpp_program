#include <iostream>
#include "stonewt.h"

int main() {
	using namespace std;
	Stonewt stn_arr[6] = {3, 14, 15};
	Stonewt stdandard = 11;
	double lbs;
	for (int i = 3; i < 6; ++i) {
		cout << "Please enter the " << i + 1 << "th element:\n";
		cin >> lbs;
		stn_arr[i] = Stonewt(lbs);
	}
	Stonewt maxm, minm;
	maxm = minm = stn_arr[0];
	int num = 0;
	for (int j = 0; j < 6; ++j) {
		if (maxm < stn_arr[j])
			maxm = stn_arr[j];
		if (minm > stn_arr[j])
			minm = stn_arr[j];
		if (stn_arr[j] >= stdandard)
			num++;
	}

	cout << "The max element is ";
	maxm.show_lbs();
	cout << "The min element is ";
	minm.show_lbs();
	cout << num << " elements >= 11 pounds\n";

	return 0;
}