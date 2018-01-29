#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"

int main() {
	using namespace std;
	srand(time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	string filename = "data.dat";
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open()) {
		cout << "Cannot open " + filename << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Enter target distance (q to quit): ";
	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target) {
			fout << steps << ": " << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		fout << steps << ": " << result << endl;
		cout << "After " << steps << " steps, the subject has the following location:\n"
		     << result << endl;
		fout << "After " << steps << " steps, the subject has the following location:\n"
		     << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		fout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl
		     << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}