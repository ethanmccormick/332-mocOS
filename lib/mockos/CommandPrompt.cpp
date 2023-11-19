
#include "mockos/CommandPrompt.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include <iostream>
#include <string>
#include <sstream>


void CommandPrompt::setFileSystem(AbstractFileSystem* filesystem) {
	this->filesystem = filesystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* factory) {
	this->factory = factory;
}

int CommandPrompt::addCommand(std::string alias, AbstractCommand* command) {
	auto insert = commands.insert(make_pair(alias, command));  // returns a pair
	if (insert.second) {
		return success;   // second value of pair is boolean insertion success
	}
	return insertionError;
}

void CommandPrompt::listCommands() {
	cout << "All supported commands: " << endl;
	for (auto it = commands.begin(); it != commands.end(); ++it) {
		pair<std::string, AbstractCommand*> entry = *it;
		cout << "   " << entry.first << endl;
	}
}

std::string CommandPrompt::prompt() {
	cout << "\nEnter a command, \"help\", \"help <command name>\", or q to quit. \n $  ";
	std::string input;
	getline(cin, input);
	return input;
}

int CommandPrompt::run(){

    while(true) {
        string result = prompt();
        if (result == "q") {
            return userQuit;
        }
        else if (result == "help"){
            listCommands();
        }
        else {
            bool isOneWord = true;
            for (char c : result){
                if (c == ' ') {
                    isOneWord = false;
                    break;
                }
            }
            if (isOneWord) {
                auto it = commands.find(result);
                if (it!=commands.end()){
                    if (it->second->execute("") != success){
                        cout << "Command \"" << result << "\" failed to execute successfully." << endl;
                    }
                }
                else {
                    cout << "Command \"" << result << "\" not found." << endl;
                }
            } else {
                //if longer than one word
                istringstream iss(result);
                string firstWord, rest;
                std::getline(iss, firstWord, ' ');
                std::getline(iss, rest);
                if (firstWord == "help") {             // test if help command used
                    auto it = commands.find(rest);
                    if (it != commands.end()) {
                        it->second->displayInfo();
                    } else {
                        cout << "Command \"" << rest << "\" not found." << endl;
                    }
                } else {
                    auto it = commands.find(firstWord);
                    if (it != commands.end()){
                        if (it->second->execute(rest) != success) {
                            cout << "Command \"" << firstWord << "\" failed to execute successfully." << endl;
                        }
                    } else {
                        cout << "Command \"" << rest << "\" not found." << endl;
                    }
                }

            }

        }

    }
}

