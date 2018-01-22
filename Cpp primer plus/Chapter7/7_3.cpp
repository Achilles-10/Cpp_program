#include <iostream>

using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show(box);

void product(box *);

int main() {
	box box1 = {"Nike", 30, 40, 50};
	product(&box1);
	show(box1);
	return 0;
}

void show(box box1) {
	cout << "Maker: " << box1.maker << endl;
	cout << "Height: " << box1.height << " Width: " << box1.width << " Length: "
	     << box1.length << endl;
	cout << "Volume: " << box1.volume << endl;
}

void product(box *box1) {
	box1->volume = box1->height * box1->width * box1->length;
}