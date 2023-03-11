#include <iostream>
#include <fstream>

#include "Filter.h"

int main() {

	std::ifstream inFile;
	std::ofstream outFile;

	Encryption e(42);
	Uppercase u;
	Copy c;

	std::cout << "Looks okay so far..." << std::endl;

	inFile.open("input.txt");
	outFile.open("encryption.txt");
	e.doFilter(inFile, outFile);

	outFile.open("uppercase.txt");
	u.doFilter(inFile, outFile);

	outFile.open("copy.txt");
	c.doFilter(inFile, outFile);

	inFile.close();
	outFile.close();

	std::cout << "This should be it..." << std::endl;
	return 0;
}