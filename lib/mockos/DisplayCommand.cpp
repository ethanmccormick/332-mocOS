
#include "mockos/DisplayCommand.h"
#include <iostream>
#include <sstream>
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;


DisplayCommand::DisplayCommand(AbstractFileSystem* filesystem) : filesystem(filesystem) { }

void DisplayCommand::displayInfo() {
	cout << "ds displays the formatted contents of a file. Usage: \"ds <filename>\"" << endl;
}

int DisplayCommand::execute(std::string args) {
	std::string filename;
	std::string option;
	istringstream stream(args);
	std::getline(stream, filename, ' ');
	std::getline(stream, option);
	AbstractFile* file = filesystem->openFile(filename);
	if (file == nullptr) {
		return fileNotFound;
	}
	if (option == "-d") {
		for (char c : file->read()) {
			cout << c;
		}
		cout << endl;
	}
	else {
		BasicDisplayVisitor* visitor = new BasicDisplayVisitor;
		file->accept(visitor);
		delete visitor;
	}
	filesystem->closeFile(file);
	cout << endl;
	return success;
}
