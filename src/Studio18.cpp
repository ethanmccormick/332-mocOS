
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	AbstractFileSystem* filesystem = new SimpleFileSystem();
	AbstractFileFactory* factory = new SimpleFileFactory();
	AbstractFile* tf1 = factory->createFile("tf1.txt");
	AbstractFile* if1 = factory->createFile("if1.img");
	filesystem->addFile(tf1->getName(), tf1);
	filesystem->addFile(if1->getName(), if1);
	//AbstractFile* opentf1 = filesystem->openFile("tf1.txt");
	//AbstractFile* openif1 = filesystem->openFile("if1.img");
	vector<char> contents = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	tf1->write(contents);
	if1->write(contents);
	//filesystem->closeFile(opentf1);
	//filesystem->closeFile(openif1);
	tf1->read();
	cout << endl;
	if1->read();

}