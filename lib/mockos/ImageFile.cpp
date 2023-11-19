//Created by Charlie Eichman on 4/6/23

#include "mockos/ImageFile.h"
#include <iostream>

ImageFile::ImageFile(std::string name) : size(0), name(name) {

}

unsigned int ImageFile::getSize() {
	return contents.size();
}

std::string ImageFile::getName() {
	return name;
}

int ImageFile::write(std::vector<char> newContents) {
	auto last = newContents.end() - 1;  // last char of newContents
	int newSize = *last - '0';   // convert last char of newContents to integer value
	contents.clear();
	int counter = 0;

	auto it = newContents.begin();
	while (it != last) {
		char c = *it;
		if ((c != 'X') && (c != ' ')) {
			contents.clear();
			size = 0;
			return badContents;
		}
		contents.push_back(c);
		++counter;
		++it;
	}
	if (counter != newSize * newSize) {
		contents.clear();
		size = 0;
		return sizeMismatch;
	}
	size = newSize;
	return success;
}

int ImageFile::append(std::vector<char> unused) {
	return methodNotSupported;
}

int ImageFile::toIndex(int row, int col) {
	return row * size + col;
}

vector<char> ImageFile::read() {
	// images are square, so size = width and height
    vector<char> result;
	for (int i = 0; i < size; ++i) {
		int row = size - i - 1;
		for (int col = 0; col < size; ++col) {
            result.push_back(contents[toIndex(row, col)]);
		}
	}
    return result;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string newname) {
	AbstractFile* newfile = new ImageFile(newname);
	newfile->write(contents);
	return newfile;
}