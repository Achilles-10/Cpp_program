#include <iostream>

using namespace std;

struct CandyBar {
	string brand;
	float weight;
	int calories;
};

int main() {

	CandyBar snack{"Mocha Munch", 2.3f, 350};

	cout << "Brand: " << snack.brand << endl;
	cout << "Weight: " << snack.weight << "g\n";
	cout << "Calories: " << snack.calories << "cal\n";

	return 0;
}
