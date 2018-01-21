#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char ch;
	int count = 0;
	string filename = "testfile.txt";
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Could not open " + filename << endl;
		exit(EXIT_FAILURE);
	}
	while (!fin.eof() && fin.get(ch)) {
		count++;
		cout << ch;
	}
	cout << "\nThere are " << count << " characters in " + filename << endl;
	fin.close();
	
	return 0;
}