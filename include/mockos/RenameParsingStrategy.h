#pragma once

#include "AbstractParsingStrategy.h"


class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	std::vector<string> parse(std::string);
};