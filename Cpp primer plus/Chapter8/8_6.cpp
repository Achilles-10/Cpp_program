#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T maxn(T [], int);

template<>
char *maxn(char *arr[], int n);

int main() {
	int array1[6] = {3, 1, 5, 9, 2, 6};
	double array2[4] = {5.3, 5.8, 9.7, 9.3};

	cout << "The max number of array1 is " << maxn(array1, 6) << endl;
	cout << "The max number of array2 is " << maxn(array2, 4) << endl;

	char *array3[5] = {"Hello world!", "My name is Achilles.", "How are you?",
	                   "Nice to meet you.", "Good night!"};
	cout << "The longest string of array3 is " << maxn(array3, 5) << endl;

	return 0;
}

template<typename T>
T maxn(T arr[], int n) {
	T max = arr[0];
	for (int i = 1; i < n; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template<>
char *maxn(char *arr[], int n) {
	int max = 0;
	for (int i = 1; i < n; ++i)
		if (strlen(arr[i]) > strlen(arr[max]))
			max = i;
	return arr[max];
}