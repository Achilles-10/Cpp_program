#include <iostream>

using namespace std;

int main() {
	int row;
	cout << "Enter number of rows: ";
	cin >> row;
	for (int i = 1; i <= row; ++i) {
		for (int j = row; j > i; --j)
			cout << '.';
		for (int k = 0; k < i; ++k)
			cout << '*';
		cout << endl;
	}

	return 0;
}
