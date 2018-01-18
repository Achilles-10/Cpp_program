#include <iostream>
#include <array>

using namespace std;

int main() {

	array<float, 3> time;
	float average;

	cout << "Please enter the three results of 40m run: \n";
	cin >> time[0] >> time[1] >> time[2];
	average = (time[0] + time[1] + time[2]) / 3;
	cout << "You average time by three times is " << average << "s\n";

	return 0;
}