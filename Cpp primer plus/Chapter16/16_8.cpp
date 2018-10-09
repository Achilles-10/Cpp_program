#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//void Show(const string &s) { cout << s << "\t"; }

int main() {
	cout.width(8);
	vector<string> vec1,vec2,temp,vec4;
	string name;
	cout << "Enter Mat's friends(enter quit to quit):\n";
	while (cin >> name && name != "quit") {
		vec1.push_back(name);
	}
	cout << "\nMat's friends:\n";
	copy(vec1.begin(),vec1.end(),ostream_iterator<string>(std::cout, " "));
	cout << endl;

	cout << "\nEnter Pat's friends(enter quit to quit):\n";
	while (cin >> name && name != "quit") {
		vec2.push_back(name);
	}
	cout << "\nPat's friends:\n";
	copy(vec2.begin(),vec2.end(),ostream_iterator<string>(std::cout, " "));
	cout << endl;

	temp.insert(temp.end(),vec1.begin(),vec1.end());
	temp.insert(temp.end(),vec2.begin(),vec2.end());
	sort(temp.begin(),temp.end());
	auto pos = unique(temp.begin(),temp.end());
	cout << "\nAll friends:\n";
	copy(temp.begin(),pos,ostream_iterator<string>(std::cout, " "));

	return 0;
}