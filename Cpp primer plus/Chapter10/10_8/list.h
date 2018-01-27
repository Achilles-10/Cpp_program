//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_LIST_H
#define CPPLEARN_LIST_H

const int MAX = 5;

typedef struct node {
	std::string name;
	int data;
} Item;

class List {
	Item item[MAX];
	int count;
public:
	List() {
		count = 0;
	}

	int countItem();

	bool add(Item &);

	bool isempty();

	bool isfull();

	void visit(void (*pf)(Item &));
};

#endif //CPPLEARN_LIST_H