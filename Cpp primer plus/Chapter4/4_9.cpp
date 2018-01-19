#include <iostream>

using namespace std;

struct CandyBar {
	string brand;
	float weight;
	int calories;
};

int main() {

	CandyBar *snack = new CandyBar[3];

	*(snack) = {"Mocha Munch", 2.3f, 350};
	*(snack + 1) = {"Dove", 1.9f, 365};
	*(snack + 2) = {"Dcosle", 2.4f, 310};

	cout << "Brand_1: " << snack[0].brand << endl;
	cout << "Weight: " << snack[0].weight << "g\n";
	cout << "Calories: " << snack[0].calories << "cal\n\n";

	cout << "Brand_2: " << snack[1].brand << endl;
	cout << "Weight: " << snack[1].weight << "g\n";
	cout << "Calories: " << snack[1].calories << "cal\n\n";

	cout << "Brand_3: " << snack[2].brand << endl;
	cout << "Weight: " << snack[2].weight << "g\n";
	cout << "Calories: " << snack[2].calories << "cal\n\n";

	delete[] snack;

	return 0;
}
