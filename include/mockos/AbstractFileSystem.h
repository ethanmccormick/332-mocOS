// Created by Charlie Eichman on 4/8/23

#pragma once

#include <string>
#include <set>
#include "AbstractFile.h"

class AbstractFileSystem {
protected:
	const static enum returnConditions {
		success,
		fileNotFound,
		fileAlreadyExists,
		nullFilePointer,
		badFileExtension,
		fileAlreadyOpen,
		fileNotOpen
	};
public:
	virtual int addFile(std::string, AbstractFile*) = 0;  // takes filename, file
	virtual int deleteFile(std::string) = 0;  // takes filename
	virtual AbstractFile* openFile(std::string) = 0;  // takes filename
	virtual int closeFile(AbstractFile*) = 0;  // takes file
	virtual std::set<string> getFileNames() = 0;
};