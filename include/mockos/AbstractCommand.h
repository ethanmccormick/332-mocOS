#pragma once

#include <string>

class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;
	virtual int execute(std::string) = 0;  // parameter holds information passed to command
	virtual void displayInfo() = 0;  // usage message
protected:
	enum returnConditions {
		success,
		fileNotCreated,
		fileNotAdded,
		fileNotFound
	};
};