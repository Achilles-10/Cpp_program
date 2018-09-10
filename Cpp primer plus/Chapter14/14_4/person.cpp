#include "person.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Person::~Person() {}

void Person::Data() const {
	cout << "Name: " << fullname << endl;
}

void Person::Get() {
	getline(cin, fullname);
}


void Gunslinger::Data() const {
	cout << "Pulling time: " << time << endl;
	cout << "Scrapes: " << scrapes << endl;
}

void Gunslinger::Show() const {
	cout << "Category: Gunslinger\n";
	Person::Data();
	Data();
}

void Gunslinger::Get() {
	cout << "Please enter pulling time and scrapes(like 0.0 0): ";
	cin >> time >> scrapes;
	while (cin.get() != '\n')
		continue;
}

void Gunslinger::Set() {
	cout << "Please enter gunslinger's name: ";
	Person::Get();
	Get();
}

void PokerPlayer::Data() const {
	cout << "Card value: " << card << endl;
}

void PokerPlayer::Show() const {
	cout << "Category: Pokerplayer\n";
	Person::Data();
	Data();
}

void PokerPlayer::Get() {
	cout << "Please enter card value: ";
	cin >> card;
	while (cin.get() != '\n')
		continue;
}

void PokerPlayer::Set() {
	cout << "Please enter pokerplayer's name: ";
	Person::Get();
	Get();
}

void BadDude::Data() const {
	Gunslinger::Data();
	PokerPlayer::Data();
}

void BadDude::Show() const {
	cout << "Category: BadDude\n";
	Person::Data();
	Data();
}

void BadDude::Get() {
	Gunslinger::Get();
	PokerPlayer::Get();
}

void BadDude::Set() {
	cout << "Please enter baddude's name: ";
	Person::Get();
	Get();
}