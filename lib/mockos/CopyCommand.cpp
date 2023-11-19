
#include "mockos/CopyCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include <sstream>
#include <iostream>

using namespace std;


CopyCommand::CopyCommand(AbstractFileSystem* filesystem) : filesystem(filesystem) { }

void CopyCommand::displayInfo() {
	cout << "cp copies the contents of an existing file to a new one with a different name. Usage: \"cp <sourcefile> <destinationfile_no_extension>\"" << endl;
}

int CopyCommand::execute(std::string args) {
	std::string filename;
	std::string extension;
	std::string newname;
	istringstream stream(args);
	std::getline(stream, filename, '.');
	std::getline(stream, extension, ' ');
	std::getline(stream, newname);
	AbstractFile* file = filesystem->openFile(filename + '.' + extension);
	if (file == nullptr) {
		return fileNotFound;
	}
	std::string newfullname = newname + '.' + extension;
	AbstractFile* newfile = file->clone(newfullname);
	filesystem->closeFile(file);
	return filesystem->addFile(newfullname, newfile);
}