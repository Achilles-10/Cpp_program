#include "tv.h"
#include <iostream>

int main() {
	using std::cout;
	Tv s42;
	cout << "Initial settings for 42\" TV: \n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 8);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();

	cout << "\nRemote's settings of grey\" Remote:\n";
	grey.act_mode();
	grey.set_act(s58);
	cout << "\nAdjusted settings for grey\" Remote:\n";
	grey.act_mode();

	return 0;

}