#include <iostream>
#include <fstream>

using namespace std;

struct patron {
	string name;
	double donation;
};

int main() {
	ifstream fin;
	string filename = "testfile.txt";
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Could not open " + filename << endl;
		exit(EXIT_FAILURE);
	}
	int num, flag = 0;
	fin >> num;
	fin.get(); // clear '\n'
	patron *donors = new patron[num];
	for (int i = 0; i < num; ++i) {
		getline(fin, donors[i].name);
		fin >> donors[i].donation;
		fin.get(); // clear '\n'
	}
	cout << "Grand Patrons:\n";
	for (int j = 0; j < num; ++j)
		if (donors[j].donation > 10000) {
			cout << donors[j].name << ": " << donors[j].donation << endl;
			flag = 1;
		}
	if (0 == flag)
		cout << "none!\n";
	flag = 0;
	cout << "Patrons:\n";
	for (int k = 0; k < num; ++k)
		if (donors[k].donation <= 10000) {
			cout << donors[k].name << ": " << donors[k].donation << endl;
			flag = 1;
		}
	if (0 == flag)
		cout << "none!\n";

	fin.close();

	return 0;
}