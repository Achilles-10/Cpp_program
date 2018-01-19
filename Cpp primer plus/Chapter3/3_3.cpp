#include <iostream>

using namespace std;

int main() {
	const float trans = 60.0;
	int degree, minute, second;
	float arc;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> degree;
	cout << "Next, enter the minutes of arc: ";
	cin >> minute;
	cout << "Finally, enter the seconds of arc: ";
	cin >> second;
	arc = degree + (minute + second / trans) / trans;
	cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = ";
	cout << arc << " degrees\n";

	return 0;

}