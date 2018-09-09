#include "pe14.h"


Wine::Wine(const char *l, int y, const int *yr, const int *bot)
		: string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}

Wine::Wine(const char *l, int y) : string(l), years(y),
                                   PairArray(ArrayInt(y), ArrayInt(y)) {}


void Wine::GetBottles() {
	int y, b;

	std::cout << "Enter " << Label() << " data for " << years
	          << " year(s):\n";
	for (int i = 0; i < years; ++i) {
		std::cout << "Enter year: ";
		std::cin >> y;
		std::cout << "Enter bottles for that year: ";
		std::cin >> b;
		PairArray::first()[i] = y;
		PairArray::second()[i] = b;
	}
}

int Wine::sum() const {
	return PairArray::second().sum();
}

void Wine::Show() const {
	std::cout << "Wine: " << Label() << std::endl
	          << "\tYear\tBottles\n";
	for (int i = 0; i < years; ++i) {
		std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i]
		          << std::endl;
	}
}

