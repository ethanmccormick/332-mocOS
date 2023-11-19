#pragma once

#include "AbstractCommand.h"
#include <string>

class AbstractFileSystem;


class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesystem;
public:
	CopyCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(std::string args);
};