#ifndef Filter_H
#define Filter_H

#include <iostream>
using namespace std;

class Filter {

public:
	virtual char transform(char ch) = 0;

	void doFilter(ifstream& in, ofstream& out) {
		char c;

		while((c = in.get()) != EOF) {

			c = transform(c);
			out << c;
		}
		in.close();
		out.close();
	}
};

class Encryption: public Filter {

	int key = 0;

public:

	Encryption(int k) {
		this->key = k;
	}
	virtual char transform(char ch) override {

		return ch + key;
	}

};

class Uppercase: public Filter {

public:

	Uppercase() {

	}
	virtual char transform(char ch) override {
		
		return toupper(ch);
	}

};

class Copy: public Filter {

public:

	Copy() {

	}
	virtual char transform(char ch) override {
		
		return ch;
	}

};
#endif