#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;

const int LIM = 10000000;

double listTime(vector<int> &vec, list<int> &lst);

double sortTimeVec(vector<int> &vec);

double sortTimeLst(list<int> &lst);

int main() {
	srand(time(NULL));
	vector<int> vi0;
	for (int i = 0; i < LIM; ++i) {
		vi0.push_back(rand() % LIM);
	}
	vector<int> vi1(vi0.size());
	list<int> li(vi0.size());
	copy(vi0.begin(), vi0.end(), vi1.begin());
	copy(vi0.begin(), vi0.end(), li.begin());
	cout << "Before sort:\nVector\t";
	copy(vi1.begin(), vi1.begin() + 15, ostream_iterator<int>(cout, " "));
	cout << "...\nList:\t";
	auto pos = li.begin();
	for (int j = 0; j < 15; ++j, ++pos) {
		cout << *pos << " ";
	}
	cout << "..." << endl;

	double s_vec_time, s_lst_time, dup_lst_time;
	s_vec_time = sortTimeVec(vi1);
	s_lst_time = sortTimeLst(li);

	cout << "After sort:\nVector:\t";
	copy(vi1.begin(), vi1.begin() + 15, ostream_iterator<int>(cout, " "));
	cout << "...\nList:\t";
	pos = li.begin();
	for (int j = 0; j < 15; ++j, ++pos) {
		cout << *pos << " ";
	}
	cout << "..." << endl;
	copy(vi0.begin(), vi0.end(), li.begin());
	dup_lst_time = listTime(vi0, li);

	cout << "     Time:\n"
	     << "   Vector:\t" << s_vec_time << endl;
	cout << "     List:\t" << s_lst_time << endl;
	cout << "Duplicate:\t" << dup_lst_time << endl;

	return 0;
}

double sortTimeVec(vector<int> &vec) {
	clock_t start, end;
	start = clock();
	sort(vec.begin(), vec.end());
	end = clock();
	return (double) (end - start) / CLOCKS_PER_SEC;
}


double listTime(vector<int> &vec, list<int> &lst) {
	clock_t start, end;
	start = clock();
	copy(lst.begin(), lst.end(), vec.begin());
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), lst.begin());
	end = clock();
	return (double) (end - start) / CLOCKS_PER_SEC;
}

double sortTimeLst(list<int> &lst) {
	clock_t start, end;
	start = clock();
	lst.sort();
	end = clock();
	return (double) (end - start) / CLOCKS_PER_SEC;
}
