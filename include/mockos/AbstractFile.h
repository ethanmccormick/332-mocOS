// Created by Charlie Eichman on 4/6/23

#pragma once

#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

using namespace std;

class AbstractFile{
public:
    virtual ~AbstractFile() = default;
    virtual AbstractFile* clone(std::string) = 0;
    virtual vector<char> read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual void accept(AbstractFileVisitor*) = 0;
protected:
    const static enum returnConditions {
        success
    };
};