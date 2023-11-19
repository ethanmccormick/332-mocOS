
#include "mockos/TextFile.h"
#include "mockos/PasswordProxy.h"
#include <iostream>

int main() {
	AbstractFile* file = new TextFile("text1.txt");
	PasswordProxy proxy(file, "password");
	std::vector<char> contents = { 'v', 'e', 'c', 't', '0', 'R' };
	proxy.write(contents);
	cout << "contents: ";
	for (char c : proxy.read()) {
		cout << c;
	}
	cout << endl;
	cout << "file size: " << proxy.getSize() << endl;

}