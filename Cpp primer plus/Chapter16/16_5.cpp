#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int NUM = 10;

template<class T>
int reduce(T ar[], int n);
bool compare(const string &s1, const string &s2);

int main() {
	long arr[NUM];
	cout << "Enter 10 numbers:\n";
	for (int i = 0; i < NUM; ++i) {
		cin >> arr[i];
	}
	cin.get();
	cout << "You've entered:\n";
	for (int i = 0; i < NUM; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int new_length_long = reduce<long>(arr, NUM);
	cout << "After reduce:\n";
	for (int i = 0; i < new_length_long; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	string str[NUM];
	cout << "Enter 10 strings:\n";
	for (int i = 0; i < NUM; ++i) {
		cin >> str[i];
	}
	cin.get();
	cout << "You've entered:\n";
	for (int i = 0; i < NUM; ++i) {
		cout << str[i] << " ";
	}
	cout << endl;
	int new_length_str = reduce<string>(str, NUM);
	cout << "After reduce:\n";
	for (int i = 0; i < new_length_str; ++i) {
		cout << str[i] << " ";
	}

	return 0;
}

template<class T>
int reduce(T ar[], int n) {
	vector<T> temp;
	for (int i = 0; i < n; ++i) {
		temp.push_back(ar[i]);
	}
	sort(temp.begin(), temp.end());
//	vector<T>::iterator pos = unique(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	int length = temp.size();
	for (int j = 0; j < length; ++j) {
		ar[j] = temp[j];
	}
	return length;
}


bool compare(const string &s1, const string &s2){
	if (s1<=s2)
		return true;
	else
		return false;
}