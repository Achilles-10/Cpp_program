//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_SALE_H
#define CPPLEARN_SALE_H

namespace SALES {
	const int QUARTERS = 4;

	class Sale {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sale() {}

		Sale(const double ar[], int n);

		void setSale();

		void showSale() const;
	};
}

#endif //CPPLEARN_SALE_H