#include <iostream>

using namespace std;

int main() {
	float mile, gallon, ratio;

	cout << "Please enter your driving distance(mile): ";
	cin >> mile;
	cout << "Now enter your fuel consumption(gallon): ";
	cin >> gallon;
	ratio = mile / gallon;
	cout << "Your fuel consumption ratio is " << ratio << "mpg\n";

	return 0;
}