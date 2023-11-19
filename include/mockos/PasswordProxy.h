#pragma once

#include <string>
#include "AbstractFileVisitor.h"
#include "AbstractFile.h"

using namespace std;

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, string); // takes file and password
	~PasswordProxy();
	AbstractFile* clone(std::string);

	std::vector<char> read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor*);
protected:
	std::string passwordPrompt();  // prompts user for a password and returns entered input
	bool correctPassword(std::string);
private:
	AbstractFile* file;
	std::string password;
	enum return_conditions {
		success,
		badPassword
	};
};