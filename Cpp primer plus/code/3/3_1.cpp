#include <iostream>

using namespace std;

int main(){
	const int trans = 12;
	int in,ft;
	cout << "Please input you height in inches (int) : ";
	cin >> in;
	ft = in/trans;
	in %= trans;
	cout << "Your height is " << ft << '\'' << in << "\'\'\n" ;

	return 0;

}