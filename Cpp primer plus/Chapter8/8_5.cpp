#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T max5(const T (&arr)[5]);

int main() {
	int arrar1[5] = {3,1,5,9,2};
	double array2[5] = {6.5,3.5,8.9,7.9,3.2};

	cout << "The max number in array1 is " << max5(arrar1) << endl;
	cout << "The max number in array2 is " << max5(array2) << endl;

	return 0;
}

template <typename T>
T max5(const T (&arr)[5]){
	T max = arr[0];
	for (int i = 1; i < 5; ++i)
		if (arr[i] > max)
			max = arr[i];

	return max;
}