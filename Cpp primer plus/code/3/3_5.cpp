#include <iostream>

using namespace std;

int main() {
	long long CN_pop, W_pop;
	float percentage;
	cout << "Enter the world's population: ";
	cin >> W_pop;
	cout << "Enter the population of the CN: ";
	cin >> CN_pop;
	percentage = (float)CN_pop / W_pop * 100;
	cout << "The population of the CN is " << percentage
	     << "% of the world population.\n";

	return 0;
}