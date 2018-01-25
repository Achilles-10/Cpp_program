#include <iostream>
#include <cstring>

const int BUF = 512;
const int N = 2;
char buffer[BUF];

struct charff {
	char dross[20];
	int slag;
};

using namespace std;

int main() {
	charff *p = new(buffer) charff[N];
	strcpy(p[0].dross, "How are you?");
	p[0].slag = 1;
	strcpy(p[1].dross, "Fine, thank you.");
	p[1].slag = 0;
	for (int i = 0; i < N; ++i) {
		cout << "p[" << i << "].dross: " << p[i].dross << endl;
		cout << "p[" << i << "].slag: " << p[i].slag << endl;
	}
	cout << "buffer's address: " << (void*)&buffer[0] << endl;
	cout << "p's address: " << (void*)p << endl;

	return 0;
}