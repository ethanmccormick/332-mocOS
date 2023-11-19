#pragma once

#include <string>
#include "AbstractCommand.h"

class AbstractFileSystem;

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	int execute(std::string);
	void displayInfo();
private:
	AbstractFileSystem* filesystem;
};