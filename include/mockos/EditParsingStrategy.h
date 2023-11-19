#pragma once

#include "AbstractParsingStrategy.h"


class EditParsingStrategy : public AbstractParsingStrategy {
public:
	std::vector<string> parse(std::string);
};