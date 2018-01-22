#include <iostream>

using namespace std;

const int Max = 5;

double *fill_array(double *, int);

void show(const double *, const double *);

void revalue(double, double *, double *);

int main() {
	double properties[Max];
	double *end = fill_array(properties, Max);
	show(properties, end);
	if (end >= properties) {
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, end);
		show(properties, end);
	}
	cout << "Done.\n";

	return 0;
}

double *fill_array(double *arr, int limit) {
	double *temp = arr;
	for (int i = 0; i < limit; ++i, ++temp) {
		cout << "Enter value #" << (i + 1) << ": ";
		if (!(cin >> *temp)) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (*temp < 0)
			break;
		arr[i] = *temp;
	}
	return --temp;
}

void show(const double *start, const double *end) {
	for (int i = 0; start + i <= end; ++i) {
		cout << "Property #" << (i + 1) << ":$ ";
		cout << *(start + i) << endl;
	}
}

void revalue(double r, double *start, double *end) {
	while (start++ <= end)
		*start *= r;
}