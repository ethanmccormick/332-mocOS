#pragma once

#include <vector>
#include <string>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual std::vector<string> parse(std::string) = 0;
};
