#include <iostream>
#include "list.h"

int List::countItem() {
	return count;
}

bool List::isfull() {
	if (count < MAX)
		return false;
	else
		return true;
}

bool List::isempty() {
	if (count == 0)
		return true;
	else
		return false;
}

bool List::add(Item &it) {
	if (isfull()) {
		std::cout << "List already full\n" << std::endl;
		return false;
	}
	else {
		item[count++] = it;
		return true;
	}
}

void List::visit(void (*pf)(Item &)) {
	for (int i = 0; i < count; ++i) {
		std::cout << "Item[" << i+1 << "]:\n";
		pf(item[i]);
	}
}