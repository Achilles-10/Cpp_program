//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_SALE_H
#define CPPLEARN_SALE_H
namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales &s, const double ar[], int n);

	void setSales(Sales &s);

	void showSales(const Sales &s);
}


#endif //CPPLEARN_SALE_H
