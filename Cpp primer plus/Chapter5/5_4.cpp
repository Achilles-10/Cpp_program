#include <iostream>

using namespace std;
const float Dintrest = 0.1;
const float Cintrest = 0.05;

int main() {
	float Daphne = 100, Cleo = 100;
	int count;
	for (count = 0; Daphne >= Cleo; ++count) {
		Daphne += 100.0f * Dintrest;
		Cleo = Cleo * (1 + Cintrest);
	}
	cout << count << " years later, Cleo's value will over Daphne's.\n";
	cout << "Daphne's value: " << Daphne << "$\n";
	cout << "Cleo's value:   " << Cleo << "$\n";

	return 0;
}