#include <iostream>
#include "list.h"

using namespace std;

void pf(Item &);

int main() {
	Item item[MAX+1]={
			{"Achilles",90},
			{"Liase",100},
			{"Victor",80},
			{"Bob",70},
			{"Jax",60},
			{"Enormous",50}
	};
	List list;
	if (list.isempty())
		cout << "list already empty\n";
	cout << "Now, add items to list.\n";
	for (int i = 0; i < MAX; ++i)
		list.add(item[i]);
	cout << "Visit items.\n";
	list.visit(pf);
	cout << "Add another item.\n";
	if (list.add(item[MAX])){
		cout << "Wrong!\n";
	};

	return 0;
}

void pf(Item &item) {
	cout << "Name: " << item.name << endl
	     << "Data: " << item.data << endl;
}