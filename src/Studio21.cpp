//
//Created by Ethan McCormick on 4/18/23
//

#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include <iostream>

int main() {
    AbstractFileSystem* filesystem = new SimpleFileSystem();
    AbstractFileFactory* filefactory = new SimpleFileFactory();
    AbstractCommand* ptr_touchCommand = new TouchCommand(filesystem, filefactory);
    CommandPrompt* ptr_commandPrompt = new CommandPrompt();
    ptr_commandPrompt->setFileFactory(filefactory);
    ptr_commandPrompt->setFileSystem(filesystem);
    ptr_commandPrompt->addCommand("touch",ptr_touchCommand);
    ptr_commandPrompt->run();

    cout << filesystem->openFile("file.txt")->getName() << endl;
    
}