#include <iostream>
#include <fstream>

#include "Filter.h"

using namespace std;

int main() {

	ifstream inFile;
	ofstream outFile;

	Encryption e(2);
	Uppercase u;
	Copy c;

	inFile.open("input.txt");
	outFile.open("encryption.txt");
	e.doFilter(inFile, outFile);

	inFile.open("input.txt");
	outFile.open("uppercase.txt");
	u.doFilter(inFile, outFile);

	inFile.open("input.txt");
	outFile.open("copy.txt");
	c.doFilter(inFile, outFile);

	return 0;
}