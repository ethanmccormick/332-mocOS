#pragma once

#include <string>
#include "AbstractFile.h"

class AbstractFileFactory {
protected:
	// return conditions enum?
public:
	virtual AbstractFile* createFile(std::string) = 0;  // takes filename
};