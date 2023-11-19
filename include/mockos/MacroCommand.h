#pragma once

#include <vector>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"


class AbstractParsingStrategy;

using namespace std;

class MacroCommand : public AbstractCommand {
private:
	vector<AbstractCommand*> commands;
	AbstractParsingStrategy* parser;
protected:
	const static enum returnConditions {
		success,
		argNumberMismatch
	};
public:
	MacroCommand();
	MacroCommand(AbstractFileSystem*);
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
	void displayInfo();
	int execute(std::string);
};