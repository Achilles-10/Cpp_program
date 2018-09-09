#include "pe14.h"


Wine::Wine(const char *l, int y, const int *yr, const int *bot)
		: label(l), years(y), pair(ArrayInt(yr, y), ArrayInt(bot, y)) {}

Wine::Wine(const char *l, int y) : label(l), years(y), pair(ArrayInt(y), ArrayInt(y)) {}

Wine::Wine(const Wine &w) {
	label=w.label;
	years=w.years;
	pair=w.pair;
}

void Wine::GetBottles() {
	int y, b;

	std::cout << "Enter " << label << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; ++i) {
		std::cout << "Enter year: ";
		std::cin >> y;
		std::cout << "Enter bottles for that year: ";
		std::cin >> b;
		pair.first()[i] = y;
		pair.second()[i] = b;
	}
}

int Wine::sum() const {
	return pair.second().sum();
}

void Wine::Show() const {
	std::cout << "Wine: " << label << std::endl
	          << "\tYear\tBottles\n";
	for (int i = 0; i < years; ++i) {
		std::cout << "\t" << pair.first()[i] << "\t" << pair.second()[i] << std::endl;
	}
}

