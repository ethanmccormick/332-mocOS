// Created by CHarlie Eichman on 4/8/23

#pragma once

#include <map>
#include <set>
#include "AbstractFile.h"
#include "AbstractFileSystem.h"

class SimpleFileSystem : public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
public:
	virtual int addFile(std::string, AbstractFile*) override;  // takes filename, file   *** Added files MUST be heap-allocated! deleteFile() calls delete on the AbstractFile*.
	virtual int deleteFile(std::string) override;  // takes filename
	virtual AbstractFile* openFile(std::string) override;  // takes filename
	virtual int closeFile(AbstractFile*) override;  // takes file
	virtual std::set<string> getFileNames() override;
};