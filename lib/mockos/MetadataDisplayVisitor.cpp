
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

void MetadataDisplayVisitor::visit_TextFile(TextFile* txtPtr) {
	cout << txtPtr->getName() << setw(20) << "text" << setw(10) << txtPtr->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imgPtr) {
	cout << imgPtr->getName() << setw(20) << "image" << setw(10) << imgPtr->getSize() << endl;
}