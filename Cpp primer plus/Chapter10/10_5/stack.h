//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_STACK_H
#define CPPLEARN_STACK_H

struct customer {
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack {
	enum {
		MAX = 10
	};
	Item items[MAX];
	int top;
public:
	Stack();

	bool isemptey() const;

	bool isfull() const;

	bool push(const Item &item);

	bool pop(Item &item);

};

#endif //CPPLEARN_STACK_H