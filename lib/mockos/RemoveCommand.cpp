
#include "mockos/RemoveCommand.h"
#include "mockos/AbstractFileSystem.h"
#include <iostream>

using namespace std;;


void RemoveCommand::displayInfo() {
	cout << "rm removes a file from the filesystem. Example: \"rm file.txt\"" << endl;
}

RemoveCommand::RemoveCommand(AbstractFileSystem* filesystem) : filesystem(filesystem) { }

int RemoveCommand::execute(std::string args) {
	return filesystem->deleteFile(args);
}