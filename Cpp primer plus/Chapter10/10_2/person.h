//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_PERSON_H
#define CPPLEARN_PERSON_H

class Person {
	static const int LIMIT = 25; // int?
	std::string lname;
	char fname[LIMIT];

public:
	Person() { lname = "", fname[0] = '\0'; }

	Person(const std::string &ln, const char *fn = "Heyyou");

	void Show() const;

	void FormalShow() const;
};


#endif //CPPLEARN_PERSON_H
