// Created by Charlie Eichman on 4/6/23

#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>

using namespace std;

int main() {
	ImageFile image("newimage.img");
	std::vector<char> contents = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	cout << image.write(contents) << endl;
	image.read();
	cout << "done with image file testing\n" << endl;

	SimpleFileSystem filesystem;
	TextFile* text = new TextFile("newtext.txt");
	filesystem.addFile("newtext.txt", text);
	filesystem.createFile("newtext2.txt");
	AbstractFile* newtext2 = filesystem.openFile("newtext2.txt");
	newtext2->write(contents);
	filesystem.closeFile(newtext2);
	filesystem.deleteFile("newtext.txt");
	newtext2->read();
	cout << endl;

}