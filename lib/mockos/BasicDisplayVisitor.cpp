//
//Created by Ethan McCormick on 4/13/23
//
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"


using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* txtPtr){

    vector<char> contents = txtPtr->read();

    for(char content : contents){
        cout << content;
    }
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *imgPtr) {

    vector<char> contents = imgPtr->read();

    vector<char> result;
    int sizeSquared = imgPtr->getSize();
    int size = sqrt(sizeSquared);
    for (int i = 0; i < size; ++i) {
        int row = size - i - 1;
        for (int col = 0; col < size; ++col) {
            int index = row * size + col;
            cout << contents[index];

        }
        cout << endl;
    }
}
