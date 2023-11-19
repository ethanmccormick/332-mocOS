//Created by Ethan McCormick on 3/28/2023

#include "mockos/TextFile.h"

using namespace std;

TextFile::TextFile(std::string fileName) {
    TextFile::name = fileName;
}


unsigned int TextFile::getSize() {
    return contents.size();
}

std::string TextFile::getName(){
    return TextFile::name;
}

int TextFile::write(std::vector<char> vector){
    contents = vector;
    return success;
}

int TextFile::append(std::vector<char> vector){
    contents.insert(contents.end(), vector.begin(), vector.end());
    return success;
}
vector<char> TextFile::read(){
    return contents;
}
void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string newname) {
    AbstractFile* newfile = new TextFile(newname);
    newfile->write(contents);
    return newfile;
}