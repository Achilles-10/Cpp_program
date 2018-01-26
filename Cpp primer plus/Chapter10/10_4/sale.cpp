#include <iostream>
#include "sale.h"

using namespace SALES;

Sale::Sale(const double *ar, int n) {
	double sum = 0.0;
	max = min = ar[0];
	for (int i = 0; i < n; ++i) {
		sales[i] = ar[i];
		sum += ar[i];
		if (max < ar[i])
			max = ar[i];
		if (min > ar[i])
			min = ar[i];
	}
	average = sum / n;
}

void Sale::setSale() {
	double sum = 0.0;
	std::cout << "Please enter 4 sales:\n";
	for (int i = 0; i < QUARTERS; ++i) {
		std::cin >> this->sales[i];
		sum += this->sales[i];
		if (0 == i)
			max = min = sales[0];
		if (max < this->sales[i])
			max = this->sales[i];
		if (min > this->sales[i])
			min = this->sales[i];
	}
	this->average = sum / QUARTERS;
}

void Sale::showSale() const{
	std::cout << "Sales are as lists:\n";
	for (int i = 0; i<QUARTERS && sales[i]; ++i)
		std::cout << sales[i] << " ";
	std::cout << "\naverage of them is " << average << std::endl;
	std::cout << "max of them is " << max << std::endl;
	std::cout << "min of them is " << min << std::endl;
}