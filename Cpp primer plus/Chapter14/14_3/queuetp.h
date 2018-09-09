#ifndef QUEUE_TP_H
#define QUEUE_TP_H

template<typename T>
class QueueTp {
private:
	struct Node {
		T item;
		struct Node *next;
	};
	enum {
		Q_SIZE = 10
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;
public:
	QueueTp(int qs = Q_SIZE) : qsize(qs) {
		front = rear = nullptr;
		items = 0;
	}

	~QueueTp();

	QueueTp &operator=(const QueueTp &q) { return *this; }

	bool isempty() const { return items == 0; }

	bool isfull() const { return items == qsize; }

	int queuecount() const { return items; }

	bool enqueue(const T &item);

	bool dequeue(T &item);
};


template<typename T>
QueueTp<T>::~QueueTp() {
	Node *temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool QueueTp<T>::enqueue(const T &item) {
	if (isfull())
		return false;
	Node *add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;

	rear = add;
	return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T &item) {
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}


#endif