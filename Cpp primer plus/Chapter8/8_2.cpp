// I used string instead of char* as I think
// string is more convenient

#include <iostream>

using namespace std;

struct CandyBar {
	string name;
	double weight;
	int heat;
};

void show(const CandyBar &candy) {
	cout << "Name: " << candy.name << endl;
	cout << "Weight: " << candy.weight << endl;
	cout << "Heat: " << candy.heat << endl;
}

void fill(CandyBar &candy, string name = " Millennium Munch", double weight = 2.85,
          int heat = 350) {
	candy.name = name;
	candy.weight = weight;
	candy.heat = heat;
}

int main() {
	CandyBar candy;
	cout << "Initializing:\n";
	fill(candy);
	show(candy);

	cout << "Please enter candy\'s name, weight\nand heat:\n";
	string name;
	double weight;
	int heat;
	getline(cin,name);
	cin >> weight;
	cin >> heat;
	fill(candy, name, weight, heat);
	cout << "After modify it:\n";
	show(candy);

	return 0;
}