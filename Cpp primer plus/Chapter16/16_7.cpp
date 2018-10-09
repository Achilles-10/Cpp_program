#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lotto(int amount, int select);
void Show(int n) {cout << n << " ";}

int main(){
	int amount,select;
	cout << "Enter the number of dots and the number selected(q to quit):\n";
	while (cin >> amount >> select){
		cin.get();
		vector<int> winners;
		winners = lotto(amount,select);
		cout << "Winners are as follows:\n";
		for_each(winners.begin(),winners.end(),Show);
		cout << endl << endl;
		cout << "Enter the number of dots and the number selected(q to quit):\n";
	}

	return 0;
}

vector<int> lotto(int amount, int select){
	vector<int> vec_in;
	vector<int> vec_out(select);
	for (int i = 0; i < amount; ++i) {
		vec_in.push_back(i+1);
	}
	random_shuffle(vec_in.begin(),vec_in.end());
	copy(vec_in.begin(),vec_in.begin()+select,vec_out.begin());
	return vec_out;
}