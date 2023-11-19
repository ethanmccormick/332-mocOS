#pragma once

#include <string>
#include "AbstractCommand.h"

class AbstractFileSystem;

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	int execute(std::string);
	void displayInfo();
private:
	AbstractFileSystem* filesystem;
};