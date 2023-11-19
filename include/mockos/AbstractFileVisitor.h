//
//Created by Ethan McCormick on 4/11/2023
//
#pragma once

#include <vector>
#include <string>

using namespace std;

class TextFile;
class ImageFile;

class AbstractFileVisitor{
public:
    virtual void visit_TextFile(TextFile* txtPtr) = 0;
    virtual void visit_ImageFile(ImageFile* imgPtr) = 0;
};