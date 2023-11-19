#pragma once

#include <map>
#include <string>

class AbstractCommand;
class AbstractFileSystem;
class AbstractFileFactory;

class CommandPrompt {
public:
	CommandPrompt() = default;
	~CommandPrompt() = default;

	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	void listCommands();
	std::string prompt();
    int run();

private:
	std::map<std::string, AbstractCommand*> commands;  // stores all supported commands
	AbstractFileSystem* filesystem;
	AbstractFileFactory* factory;

	enum returnConditions {
		success,
		insertionError,
        userQuit,
        commandFailedToExecute,
        commandNotFound,
	};
};