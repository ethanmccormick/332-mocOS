#pragma once

#include <string>
#include <vector>
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

using namespace std;

class TextFile : public AbstractFile {
public:
    TextFile(std::string name);
    AbstractFile* clone(std::string);
    virtual vector<char> read() override;
    virtual int write(std::vector<char> vector) override;
    virtual int append(std::vector<char>) override;
    virtual unsigned int getSize() override;
    virtual std::string getName() override;
    virtual void accept(AbstractFileVisitor*) override;
private:
    std::vector<char> contents;
    std::string name;  // with file extension
};