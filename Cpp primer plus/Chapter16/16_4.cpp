#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM = 10;
int reduce(long ar[],int n);

int main(){
	long arr[NUM];
	cout << "Enter 10 numbers:\n" ;
	for (int i = 0; i < NUM; ++i) {
		cin >> arr[i];
	}
	cin.get();
	cout << "You've entered:\n";
	for (int i = 0; i < NUM; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int new_length = reduce(arr,NUM);
	cout << "After reduce:\n";
	for (int i = 0; i < new_length; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}

int reduce(long ar[],int n){
	vector<long> temp;
	for (int i = 0; i < n; ++i) {
		temp.push_back(ar[i]);
	}
	sort(temp.begin(),temp.end());
	vector<long>::iterator pos = unique(temp.begin(),temp.end());
	temp.erase(pos,temp.end());
	int length = temp.size();
	for (int j = 0; j < length; ++j) {
		ar[j] = temp[j];
	}
	return length;
}