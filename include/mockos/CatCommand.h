#pragma once

#include "AbstractCommand.h"

class AbstractFileSystem;

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesystem;
public:
	CatCommand(AbstractFileSystem*);
	int execute(std::string);  // parameter holds information passed to command
	void displayInfo();  // usage message
};