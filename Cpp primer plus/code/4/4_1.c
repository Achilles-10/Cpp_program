#include <iostream>

using namespace std;

struct person {
	string firstName;
	string lastName;
	char grade;
	int age;
} person1;

int main() {

	cout << "What is your first name? ";
	getline(cin, person1.firstName);
	cout << "What is your last name? ";
	getline(cin, person1.lastName);
	cout << "What letter grade do you deserve? ";
	cin >> person1.grade;
	cout << "What is your age? ";
	cin >> person1.age;
	cout << "Name: " + person1.lastName + ',' + person1.firstName << endl;
	cout << "Grade: " << (char) (person1.grade + 1) << endl;
	cout << "Age: " << person1.age << endl;

	return 0;

}