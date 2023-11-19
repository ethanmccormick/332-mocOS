
#include "mockos/SimpleFileFactory.h"
#include <sstream>
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(std::string filename) {
	istringstream stream(filename);
	std::string name;
	std::string extension;
	std::getline(stream, name, '.');
	std::getline(stream, extension);
	if (extension.compare("txt") == 0) {  // if they're equal
		TextFile* text = new TextFile(filename);
		return text;
	}
	else if (extension.compare("img") == 0) {  // if they're equal
		ImageFile* img = new ImageFile(filename);
		return img;
	}
	else return nullptr;
}