#include <iostream>

using namespace std;

const int arSize = 10;

int Fill_array(double *, int);

void Show_array(const double *, int);

void Reverse_array(double *, int);


int main() {
	double arr[arSize];
	int size = Fill_array(arr, arSize);
	Show_array(arr, size);
	Reverse_array(arr, size);
	cout << "After reverse:\n";
	Show_array(arr, size);
	cout << "After reverse:\n";
	Reverse_array(arr + 1, size - 2);
	Show_array(arr, size);

	return 0;
}

int Fill_array(double *arr, int size) {
	cout << "Please enter several numbers up to " << arSize << " (q to quit):\n";
	int i = 0;
	while (cin >> arr[i++] && i < size);
	return i - 1;
}

void Show_array(const double *arr, int size) {
	cout << "This array includes:\n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double *arr, int size) {
	int i, j;
	double t;
	for (i = 0, j = size - 1; i < j; i++, j--) {
		t = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = t;
	}
}