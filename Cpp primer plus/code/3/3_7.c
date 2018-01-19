#include <iostream>

using namespace std;

int main() {
	const float mile = 62.14, gallon = 3.875;
	float ration, mpg;

	cout << "Please enter your fuel consumption ratio(L/100km): ";
	cin >> ration;
	mpg = mile / (ration / gallon);
	cout << "Your fuel consumption ratio(mpg) is: " << mpg << "mpg\n";

	return 0;
}