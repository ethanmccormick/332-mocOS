#pragma once

#include <string>
#include "AbstractCommand.h"

class AbstractFileSystem;

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesystem;
public:
	DisplayCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(std::string);
};