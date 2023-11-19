//
//Created by Ethan McCormick on 4/18/23
//

#pragma once
#include "mockos/TouchCommand.h"
#include <iostream>
#include "mockos/PasswordProxy.h"
#include <sstream>
#include "mockos/AbstractFile.h"


using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem * filesystem, AbstractFileFactory * filefactory) : filesystem(filesystem), filefactory(filefactory) { }

void TouchCommand::displayInfo() {
    cout << "touch creates a file. Can be invoked with the command: \"touch <filename>.<extension>\". Option \"-p\" after the filename sets a password on the new file." << endl;
}

int TouchCommand::execute(string args) {
    std::string filename;
    std::string option;
    istringstream stream(args);
    std::getline(stream, filename, ' ');
    std::getline(stream, option);
    AbstractFile* file = filefactory->createFile(filename);
    if (file == nullptr){
        return fileNotCreated;
    }
    if (option == "-p") {
        cout << "Enter password for file " << filename << ":" << endl;
        std::string password;
        cin >> password;
        AbstractFile* proxy = new PasswordProxy(file, password);

        int added = filesystem->addFile(filename, proxy);
        if (added != success) {
            delete file;
            delete proxy;
            return fileNotAdded;
        }
    }
    else {
        int added = filesystem->addFile(filename, file);
        if (added != success) {
            delete file;
            return fileNotAdded;
        }
    }

    cout << "File \"" << filename << "\" created." << endl;
    return success;
}