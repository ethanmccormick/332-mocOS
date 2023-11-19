
#include "mockos/AbstractParsingStrategy.h"
#include "mockos/MacroCommand.h"
#include "mockos/AbstractCommand.h"
#include <iostream>

using namespace std;

void MacroCommand::displayInfo() {
	cout << "Help is disabled for macro commands. See documentation for details." << endl;
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* newparser) {
	parser = newparser;
}

void MacroCommand::addCommand(AbstractCommand* command) {
	return commands.push_back(command);
}

MacroCommand::MacroCommand(AbstractFileSystem* filesystem) : parser(nullptr)  { }

MacroCommand::MacroCommand() : parser(nullptr) { }

int MacroCommand::execute(std::string args) {
	vector<string> parsed_args = parser->parse(args);
	if (parsed_args.size() != commands.size()) {
		return argNumberMismatch;
	}
	for (int i = 0; i < commands.size(); ++i) {
		AbstractCommand* command = commands[i];
		std::string arg = parsed_args[i];
		int result = command->execute(arg);
		if (result != success) {
			return result;
		}
	}
	return success;
}