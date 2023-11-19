//Created by Charlie Eichman on 4/6/23

#pragma once

#include <string>
#include <vector>
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class ImageFile : public AbstractFile {
private:
	std::string name;
	std::vector<char> contents;
	char size;

	enum returnConditions {
		success,
		sizeMismatch,
		badContents,
		methodNotSupported
	};
protected:
	int toIndex(int, int);   // returns an index based on x/y coordinates in image
public:
	ImageFile(std::string);
	AbstractFile* clone(std::string);
	virtual vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
    virtual void accept(AbstractFileVisitor*) override;

};