#include <iostream>

using namespace std;

struct PizzaInfo {
	string name;
	float diameter;
	float weight;
};

int main() {

	PizzaInfo pizza;

	cout << "Please input the company's name: ";
	getline(cin, pizza.name);
	cout << "Please input pizza's diameter: ";
	cin >> pizza.diameter;
	cout << "Please input pizza's weight: ";
	cin >> pizza.weight;
	cout << "Name: " + pizza.name << endl;
	cout << "Diameter: " << pizza.diameter << "\'\n";
	cout << "Weight: " << pizza.weight << "g\n";

	return 0;

}
