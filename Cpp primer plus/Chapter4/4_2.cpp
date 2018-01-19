#include <iostream>

using namespace std;

int main() {

	string name,dessert;

	cout << "Enter your name:\n";
	getline(cin,name);
	cout << "Enter your favorite dessert:\n";
	getline(cin,dessert);
	cout << "I have some delicious " + dessert + " for you, " + name + ".\n";

	return 0;

}
