#include <iostream>
#include <array>

using namespace std;

int main() {
	array<double, 10> arr;
	int ct1 = 0, ct2 = 0;
	double sum = 0.0, ave;
	cout << "Please enter several numbers(up to 10):\n";

	while (ct1 < 10 && cin >> arr[ct1])
		sum += arr[ct1++];
	ave = sum / (ct1 - 1);

	for (int i = 0; i < ct1; ++i)
		if (arr[i] > ave)
			ct2++;

	cout << ave << " = average of " << ct1-1 << " numbers\n";
	cout << ct2 << " of them are above the average\n";

	return 0;
}