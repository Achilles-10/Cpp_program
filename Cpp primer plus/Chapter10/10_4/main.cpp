#include <iostream>
#include "sale.h"

using namespace std;
using namespace SALES;

int main() {
	double arr[QUARTERS] = {3.1,1.4,1.5,2.6};

	Sale sale1(arr,QUARTERS);
	Sale sale2;
	sale2.setSale();
	cout << "sale1:\n";
	sale1.showSale();
	cout << "sale2:\n";
	sale2.showSale();

	return 0;
}