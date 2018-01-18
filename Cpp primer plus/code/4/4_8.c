#include <iostream>

using namespace std;

struct PizzaInfo {
	string name;
	float diameter;
	float weight;
};

int main() {

	PizzaInfo *p = new PizzaInfo;

	cout << "Please input pizza's diameter: ";
	cin >> p->diameter;
	cin.get();
	cout << "Please input the company's name: ";
	getline(cin, p->name);
	cout << "Please input pizza's weight: ";
	cin >> p->weight;
	cout << "Name: " + p->name << endl;
	cout << "Diameter: " << p->diameter << "\'\n";
	cout << "Weight: " << p->weight << "g\n";

	delete p;

	return 0;

}