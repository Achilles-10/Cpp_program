#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

const int MIN_PER_HR = 60;

class Customer {
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }

	void set(long when);

	long when() const { return arrive; }

	int ptime() const { return processtime; }
};

typedef Customer Item;

bool newcustomer(double x);

int main() {
	using namespace std;

	srand(time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	queue<Item> line;

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	long cycle_limit = MIN_PER_HR * hours;

	cout << "Enter the average number of customer per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cost;
	min_per_cost = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cycle_limit; cycle++) {
		if (newcustomer(min_per_cost)) {
			if (line.size() == qs)
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty()) {
			temp = line.front();
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}

	if (customers > 0) {
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << "Q1: " << (double) sum_line / cycle_limit << endl;
		cout << "average wait time: " << (double) line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	return 0;

}

bool newcustomer(double x) {
	return (rand() * x / RAND_MAX < 1);
}

void Customer::set(long when) {
	processtime = std::rand() % 3 + 1;
	arrive = when;
}