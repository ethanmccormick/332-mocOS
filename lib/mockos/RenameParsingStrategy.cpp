
#include "mockos/RenameParsingStrategy.h"
#include <sstream>


using namespace std;

vector<string> RenameParsingStrategy::parse(std::string args) {
	istringstream stream(args);
	string existing_name;
	string new_name;
	getline(stream, existing_name, ' ');
	getline(stream, new_name, ' ');
	vector<string> parsed;
	parsed.push_back(existing_name + " " + new_name);
	parsed.push_back(existing_name);
	return parsed;
}
