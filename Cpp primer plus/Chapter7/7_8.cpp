#include <iostream>

using namespace std;

const int Seasons = 4;
const char *Snames[] = {
		"Spring", "Summer", "Fall", "Winter"
};

struct expense {
	double expenses[Seasons];
};

//void fill(double *, int);
void fill(expense*, int);

void show(const double *, int);

int main() {
	expense *exp = new expense;
	fill(exp, Seasons);
	show(exp->expenses, Seasons);
	delete exp;
//	double expenses[Seasons];
//	fill(expenses, Seasons);
//	show(expenses,Seasons);

	return 0;
}

//void fill(double *arr, int size) {
//	for (int i = 0; i < size; ++i) {
//		cout << "Enter " << Snames[i] << " expenses: ";
//		cin >> arr[i];
//	}
//}

void fill(expense *exp, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> exp->expenses[i];
	}
}

void show(const double *arr, int size) {
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < size; ++i) {
		cout << Snames[i] << ": $" << arr[i] << endl;
		total += arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
}