#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

//void Show(const string &s) { cout << s << "\t"; }

int main() {
	cout.width(8);
	vector<string> vec1,vec2,temp;
	set<string> friends;
	string name;
	cout << "Enter Mat's friends(enter quit to quit):\n";
	while (cin >> name && name != "quit") {
		vec1.push_back(name);
	}
	cout << "Mat's friends:\n";
	copy(vec1.begin(),vec1.end(),ostream_iterator<string>(std::cout, " "));
	cout << endl;

	cout << "Enter Pat's friends(enter quit to quit):\n";
	while (cin >> name && name != "quit") {
		vec2.push_back(name);
	}
	cout << "Pat's friends:\n";
	copy(vec2.begin(),vec2.end(),ostream_iterator<string>(std::cout, " "));
	cout << endl;

	friends.insert(vec1.begin(),vec1.end());
	friends.insert(vec2.begin(),vec2.end());
	copy(friends.begin(),friends.end(),ostream_iterator<string>(cout," "));

//	temp.insert(temp.end(),vec1.begin(),vec1.end());
//	temp.insert(temp.end(),vec2.begin(),vec2.end());
//	sort(temp.begin(),temp.end());
//	auto pos = unique(temp.begin(),temp.end());
//	cout << "\nAll friends:\n";
//	copy(temp.begin(),pos,ostream_iterator<string>(cout, " "));

	return 0;
}