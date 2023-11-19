
#include "mockos/CatCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/AbstractFileSystem.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* filesystem) : filesystem(filesystem) { }

void CatCommand::displayInfo() {
	cout << "cat is used to write to a file. Usage: \"cat <filename> [-a]\".\nUse option \"-a\" to append rather than overwrite current contents.\nUse \":wq\" to save and exit, or \":q\" to discard changes." << endl;
}

int CatCommand::execute(std::string args) {
	std::string filename;
	std::string option;
	istringstream stream(args);
	std::getline(stream, filename, ' ');
	std::getline(stream, option);
	AbstractFile* file = filesystem->openFile(filename);
	if (file == nullptr) {
		return fileNotFound;
	}
	if (option == "-a") {
		for (char c : file->read()) {
			cout << c;
		}
		cout << endl << "Contents to append: " << endl;
	}
	else {
		cout << "Contents to write: " << endl;
	}
	vector<string> input_lines;
	std::string cur_input = "";
	while ((cur_input != ":q") && (cur_input != ":wq")) {
		getline(cin, cur_input);
		if ((cur_input == ":q") || (cur_input == ":wq")) {
			break;
		}
		input_lines.push_back(cur_input);
	}
	if (cur_input == ":q") {
		cout << "Changes discarded." << endl;
		return success;
	}
	else {
		vector<char> reconstituted;
		for (std::string line : input_lines) {
			for (char c : line) {
				reconstituted.push_back(c);
			}
			reconstituted.push_back('\n');   // replace newline lost with std::getline()
		}
		reconstituted.erase(reconstituted.end() - 1);   // get rid of newline added at end
		if (option == "-a") {
			//append
			int append_result = file->append(reconstituted);
			filesystem->closeFile(file);
			return append_result;
		}
		else {
			//overwrite
			int write_result = file->write(reconstituted);
			filesystem->closeFile(file);
			return write_result;
		}
	}
}