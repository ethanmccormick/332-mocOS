#pragma once

#include "TextFile.h"
#include "ImageFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* txtPtr);
	virtual void visit_ImageFile(ImageFile* imgPtr);
};