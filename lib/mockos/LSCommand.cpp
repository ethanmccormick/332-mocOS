
#include "mockos/LSCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;


void LSCommand::displayInfo() {
	cout << "ls displays all files in the current filesystem. Use \"ls -m\" to display metadata." << endl;
}

LSCommand::LSCommand(AbstractFileSystem* filesystem) : filesystem(filesystem) { }

int LSCommand::execute(std::string args) {
	if (args == "-m") {
		// metadata mode
		MetadataDisplayVisitor* visitor = new MetadataDisplayVisitor();
		for (std::string name : filesystem->getFileNames()) {
			AbstractFile* file = filesystem->openFile(name);
			if (file == nullptr) {
				return fileNotFound;
			}
			file->accept(visitor);
			filesystem->closeFile(file);
		}
		delete visitor;
		cout << endl;
		return success;
	}
	else {  // non metadata mode
		set<string> names = filesystem->getFileNames();
		auto name = names.begin();
		while (name != names.end()) {
			cout << *name << std::setw(20);
			++name;
			if (name != names.end()) {
				cout << *name << endl;
				++name;
			}
		}
		cout << endl;
		return success;
	}
}
