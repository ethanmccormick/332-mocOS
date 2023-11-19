
#include "mockos/EditParsingStrategy.h"
#include <sstream>


using namespace std;

vector<string> EditParsingStrategy::parse(std::string args) {
	istringstream stream(args);
	string filename;
	getline(stream, filename, ' ');
	vector<string> parsed;
	parsed.push_back(filename + " -a");   // append with cat
	parsed.push_back(filename);           // formatted output with ds
	return parsed;
}