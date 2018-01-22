#include <iostream>

using namespace std;

int input(float **);

void output(const float *, int);

float average(const float *, int);

int main() {
	float arr[10], ave, *pt = arr;
	int size;
	size = input(&pt);
	output(arr, size);
	ave = average(arr, size);
	cout << "Your average grade is: " << ave << endl;

	return 0;
}

int input(float **arr) {
	cout << "Please enter your golf grade up to ten(q to quit):\n";
	int i = 0;
	while (cin >> (*arr)[i++] && i < 10);

	return i;
}

void output(const float *arr, int size) {
	cout << "Your grade are as follows:\n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

float average(const float *arr, int size) {
	float sum = 0.0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	return sum / size;
}