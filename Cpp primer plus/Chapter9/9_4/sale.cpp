//
// Created by 10299 on 2018/1/25.
//

#include <iostream>
#include "sale.h"

namespace SALES {
	void setSales(Sales &s, const double ar[], int n) {
		double sum = 0.0;
		s.max = s.min = ar[0];
		for (int i = 0; i < n; ++i) {
			s.sales[i] = ar[i];
			sum += ar[i];
			if (ar[i] > s.max)
				s.max = ar[i];
			if (ar[i] < s.min)
				s.min = ar[i];
		}
		s.average = sum / n;
	}

	void setSales(Sales &s) {
		double sum = 0.0;
		std::cout << "Please enter 4 sales:\n";
		for (int i = 0; i < QUARTERS; ++i) {
			std::cin >> s.sales[i];
			sum += s.sales[i];
		}
		s.average = sum / QUARTERS;
		s.max = s.min = s.sales[0];
		for (int j = 0; j < QUARTERS; ++j) {
			if (s.sales[j] > s.max)
				s.max = s.sales[j];
			if (s.sales[j] < s.min)
				s.min = s.sales[j];
		}
	}

	void showSales(const Sales &s) {
		std::cout << "Sales are as lists:\n";
		for (int i = 0; i<QUARTERS && s.sales[i]; ++i)
			std::cout << s.sales[i] << " ";
		std::cout << "\naverage of them is " << s.average << std::endl;
		std::cout << "max of them is " << s.max << std::endl;
		std::cout << "min of them is " << s.min << std::endl;
	}
}