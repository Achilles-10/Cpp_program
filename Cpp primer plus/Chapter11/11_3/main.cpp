#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main() {
	using namespace std;
	srand(time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	unsigned long max;
	unsigned long min;
	unsigned long sum = 0;
	double target;
	double dstep;
	double average = 0.0;
	int N, i = 0;
	cout << "Enter a number N: ";
	cin >> N;
	cout << "Enter target distance: ";
	cin >> target;
	cout << "Enter step length: ";
	if (!(cin >> dstep)) {
		cout << "Wrong step length!\n";
		exit(EXIT_FAILURE);
	}
	while (i < N) {
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		if (i == 0)
			max = min = steps;
		if (max<steps)
			max = steps;
		if (min > steps)
			min = steps;
		sum += steps;
		steps = 0;
		result.reset(0.0, 0.0);
		++i;
	}
	average = sum / N;
	cout << "In " << N << " times walk, max steps is " << max
	     << ", min steps is " << min << ",\naverage steps is " << average << endl;
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}