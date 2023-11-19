//
// Created by Ethan McCormick on 4/18/23
//
#pragma once
#include "AbstractCommand.h"
#include <string>
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"


using namespace std;


class TouchCommand : public AbstractCommand{
public:
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(string) override;
private:
    AbstractFileSystem* filesystem;
    AbstractFileFactory* filefactory;
};