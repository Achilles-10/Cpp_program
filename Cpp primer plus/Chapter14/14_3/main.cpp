#include <cstring>
#include <iostream>
#include "worker.h"
#include "queuetp.h"

const int SIZE = 3;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	QueueTp<Worker> q(SIZE);

	if (q.isempty())
		cout << "Queue is empty\n" << endl;

	cout << "Add worker1 to queue" << endl;
	Worker w1("Achilles Zhang", 10299L);
	q.enqueue(w1);

	cout << "Add worker2 to queue" << endl;
	Worker w2("Victor Liang", 99725L);
	q.enqueue(w2);

	cout << "Add worker3 to queue\n" << endl;
	Worker w3("Bob Ren", 53140L);
	q.enqueue(w3);

	if (q.isfull())
		cout << "queue is full" << endl;


	for (int i = 0; i < SIZE; ++i) {
		cout << "\nDelete worker" << i+1 <<" from queue\n";
		Worker temp;
		q.dequeue(temp);
		temp.Show();
	}

	return 0;
}