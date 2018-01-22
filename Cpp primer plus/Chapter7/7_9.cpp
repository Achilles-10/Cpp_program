#include <iostream>

using namespace std;
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student [], int);

void display1(student);

void display2(const student *);

void display3(const student[], int);

int main() {
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n');

	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; ++i) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";

	return 0;
}

int getinfo(student pa[], int n) {
	cout << "Enter students\' information:\n";
	int i;
	for (i = 0; i < n; ++i) {
		cout << "student #" << (i+1) << ":\n";
		cin.getline((pa + i)->fullname, SLEN);
		cin.getline((pa+i)->hobby,SLEN);
		cin >> (pa + i)->ooplevel;
		cin.get();
	}
	return i;
}

void display1(student stu){
	cout << "Fullname: " << stu.fullname << endl;
	cout << "Hobby: " << stu.hobby << endl;
	cout << "Ooplevel: " << stu.ooplevel << endl;
}

void display2(const student *stu){
	cout << "Fullname: " << stu->fullname << endl;
	cout << "Hobby: " << stu->hobby << endl;
	cout << "Ooplevel: " << stu->ooplevel << endl;

}

void display3(const student stu[], int n){
	for (int i = 0; i < n; ++i) {
		cout << "student #" << i << ":\n";
		cout << "Fullname: " << (stu+i)->fullname << endl;
		cout << "Hobby: " << (stu+i)->hobby << endl;
		cout << "Ooplevel: " << (stu+i)->ooplevel << endl;
	}
}