//
//Created by Ethan McCormick on 4/11/2023
//
#pragma once

#include <vector>
#include <string>
#include "AbstractFileVisitor.h"


using namespace std;

class BasicDisplayVisitor : public AbstractFileVisitor {
    virtual void visit_TextFile(TextFile* txtPtr) override;
    virtual void visit_ImageFile(ImageFile* imgPtr) override;
};
