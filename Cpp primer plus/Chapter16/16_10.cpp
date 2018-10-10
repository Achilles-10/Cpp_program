#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Review {
	string title;
	int rating;
	double price;
};

bool operator<(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2);

bool RatingAsc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2);

bool PriceAsc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2);

bool PriceDesc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2);

bool FillReview(shared_ptr<Review> &rptr);

void ShowReview(const shared_ptr<Review> &rptr);

void ShowMenu();

int main() {
	vector<shared_ptr<Review> > books;

	shared_ptr<Review> temp_ptr;
	while (FillReview(temp_ptr))
		books.push_back(temp_ptr);

	if (books.size() > 0) {
		ShowMenu();
		char choice;
		while (cin >> choice && choice != '6') {
			vector<shared_ptr<Review> > books_cpy(books);
			switch (choice) {
				case '1':
					cout << "Original order:" << endl;
					cout << "Rating\tBook\tPrice\n";
					for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
					break;
				case '2':
					cout << "Alphabet order:" << endl;
					cout << "Rating\tBook\tPrice\n";
					sort(books_cpy.begin(), books_cpy.end());
					for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
					break;
				case '3':
					cout << "Rating ascending:" << endl;
					cout << "Rating\tBook\tPrice\n";
					sort(books_cpy.begin(), books_cpy.end(), RatingAsc);
					for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
					break;
				case '4':
					cout << "Price ascending:" << endl;
					cout << "Rating\tBook\tPrice\n";
					sort(books_cpy.begin(), books_cpy.end(), PriceAsc);
					for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
					break;
				case '5':
					cout << "Price descending:" << endl;
					cout << "Rating\tBook\tPrice\n";
					sort(books_cpy.begin(), books_cpy.end(), PriceDesc);
					for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
					break;
			}

			ShowMenu();
		}
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	// cin.get();
	return 0;
}

bool operator<(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2) {
	return p1->title <= p2->title;
}

bool RatingAsc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2) {
	return p1->rating <= p2->rating;
}

bool PriceAsc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2) {
	return p1->price <= p2->price;
}

bool PriceDesc(const shared_ptr<Review> &p1, const shared_ptr<Review> &p2) {
	return p1->price >= p2->price;
}

bool FillReview(shared_ptr<Review> &rptr) {
	// allocate memory
	rptr = shared_ptr<Review>(new Review);

	cout << "Enter book title (quit to quit): ";
	getline(cin, rptr->title);
	if (rptr->title == "quit")
		return false;

	cout << "Enter book rating: ";
	cin >> rptr->rating;
	if (!cin)
		return false;

	cout << "Enter book price: ";
	cin >> rptr->price;
	if (!cin)
		return false;

	// get rid of rest of input line
	while (cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const shared_ptr<Review> &rptr) {
	cout << rptr->rating << "\t" << rptr->title << "\t" << rptr->price << endl;
}

void ShowMenu() {
	cout << "---------------------------------------------------------" << endl;
	cout << "1.original order   2.alphabet order    3.rating ascending" << endl;
	cout << "4.price ascending  5.price descending  6.quit" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Your choice: ";
}