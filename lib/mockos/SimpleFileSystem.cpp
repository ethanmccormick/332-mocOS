
#include "mockos/SimpleFileSystem.h"
#include <sstream>
#include <string>
//#include "mockos\TextFile.h"
//#include "mockos\ImageFile.h"

using namespace std;

int SimpleFileSystem::addFile(std::string filename, AbstractFile* file) {
	auto search = files.find(filename);
	if (search != files.end()) return fileAlreadyExists;
	if (file == nullptr) return nullFilePointer;
	files.insert(make_pair(filename, file));
	return success;
}

AbstractFile* SimpleFileSystem::openFile(std::string filename) {
	auto search = files.find(filename);
	if (search == files.end()) return nullptr;
	AbstractFile* file = search->second;
	if (openFiles.find(file) != openFiles.end()) return nullptr;  // if file already exists in set of open files
	openFiles.insert(file);
	return file;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	auto search = openFiles.find(file);
	if (search == openFiles.end()) return fileNotOpen;  // if file isn't open
	openFiles.erase(file);
	return success;
}

int SimpleFileSystem::deleteFile(std::string filename) {
	auto search = files.find(filename);
	if (search == files.end()) return fileNotFound;  // if file doesn't exist
	AbstractFile* file = search->second;
	auto open = openFiles.find(file);
	if (open != openFiles.end()) return fileAlreadyOpen; // if the file's open when trying to be deleted
	files.erase(filename);
	delete file;
	return success;
}

std::set<string> SimpleFileSystem::getFileNames() {
	std::set<string> names;
	for (auto entry : files) {
		std::string key = entry.first;
		names.insert(key);
	}
	return names;
}