
#include "mockos/PasswordProxy.h"
#include "mockos/AbstractFile.h"
#include <iostream>

PasswordProxy::PasswordProxy(AbstractFile* file, std::string password) : file(file), password(password) { }

PasswordProxy::~PasswordProxy() {
	delete file;
}

std::string PasswordProxy::passwordPrompt() {
	cout << "Enter password to unlock \"" << file->getName() << "\"" << endl;
	std::string input;
	cin >> input;
	return input;
}

bool PasswordProxy::correctPassword(std::string input) {
	if (input.compare(password) == 0) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	std::string input = passwordPrompt();
	if (!correctPassword(input)) {
		std::vector<char> empty;
		return empty;
	}
	return file->read();
}

int PasswordProxy::write(std::vector<char> contents) {
	std::string input = passwordPrompt();
	if (!correctPassword(input)) {
		return badPassword;
	}
	return file->write(contents);
}

int PasswordProxy::append(std::vector<char> contents) {
	std::string input = passwordPrompt();
	if (!correctPassword(input)) {
		return badPassword;
	}
	return file->append(contents);
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

std::string PasswordProxy::getName() {
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	std::string input = passwordPrompt();
	if (!correctPassword(input)) {
		return;
	}
	file->accept(visitor);
}

AbstractFile* PasswordProxy::clone(std::string newname) {
	AbstractFile* cloned = file->clone(newname);
	AbstractFile* newproxy = new PasswordProxy(cloned, password);
	return newproxy;
}