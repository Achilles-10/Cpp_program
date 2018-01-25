#include <iostream>
#include "sale.h"

using namespace std;
using namespace SALES;

Sales s1, s2;

int main() {
	double array1[QUARTERS] = {3.1, 4.1, 5.9, 2.6};
	cout << "array1:\n";
	for (int i = 0; i < QUARTERS; ++i)
		cout << array1[i] << " ";
	cout << "\nInitialize s1 with array1\n";
	setSales(s1,array1,QUARTERS);
	showSales(s1);
	cout << "Gathers sales for s2 interactively\n";
	setSales(s2);
	showSales(s2);

	return 0;
}