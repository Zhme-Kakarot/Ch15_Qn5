#ifndef Filter_H
#define Filter_H

#include <iostream>
using namespace std;

class Filter {

public:
	virtual char transform(char ch) = 0;

	void doFilter(ifstream& in, ofstream& out) {
		char c = in.get();

		while(c != '\0') {

			c = transform(c);
			out << c;
			c = in.get();
		}
	}
};

class Encryption: public Filter {

	int key = 0;

public:

	Encryption(int k) {
		key = k;
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
		if(ch == '\s' || ch == '\t' || ch == '.' || ch == '\n' || ch == '\'' || ch == '\"') 
			return ch;
		else
			return ch - 32;
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