//Created by Ethan McCormick on 3/28/2023

#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/MacroCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/TouchCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/EditParsingStrategy.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"

int main(int argc, char argv[]) {

	CommandPrompt* prompt = new CommandPrompt();
	AbstractFileSystem* filesystem = new SimpleFileSystem();
	AbstractFileFactory* filefactory = new SimpleFileFactory();
	prompt->setFileFactory(filefactory);
	prompt->setFileSystem(filesystem);

	// add primitive commands
	AbstractCommand* copy = new CopyCommand(filesystem);
	AbstractCommand* remove = new RemoveCommand(filesystem);
	AbstractCommand* touch = new TouchCommand(filesystem, filefactory);
	AbstractCommand* ls = new LSCommand(filesystem);
	AbstractCommand* cat = new CatCommand(filesystem);
	AbstractCommand* ds = new DisplayCommand(filesystem);
	prompt->addCommand("cp", copy);
	prompt->addCommand("rm", remove);
	prompt->addCommand("touch", touch);
	prompt->addCommand("ls", ls);
	prompt->addCommand("cat", cat);
	prompt->addCommand("ds", ds);

	// rename usage: rn <existing_name>.<extension> <new_name_no_extension>
	AbstractParsingStrategy* renamer = new RenameParsingStrategy();
	MacroCommand* rename = new MacroCommand();
	rename->addCommand(copy);
	rename->addCommand(remove);
	rename->setParseStrategy(renamer);
	prompt->addCommand("rn", rename);
	// edit usage: edit <filename>
	// uses cat -a and ds to write to and display new formatted file contents
	AbstractParsingStrategy* editer = new EditParsingStrategy();
	MacroCommand* edit = new MacroCommand();
	edit->addCommand(cat);
	edit->addCommand(ds);
	edit->setParseStrategy(editer);
	prompt->addCommand("edit", edit);

	return prompt->run();

}