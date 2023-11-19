
#include "mockos/AbstractFile.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    // Created local test text file
    TextFile testFile("test.txt");;
    vector<char> fileContents = {'T', 'h', 'i', 's', ' ', 't', 'h', 'e', ' ', 't', 'e', 's', 't', ' ', 'f', 'i', 'l', 'e'};
    testFile.write(fileContents);

    // read file into a local variable
    vector<char> readFile = testFile.read();

    cout << "Before edit: ";
    for (auto c : readFile) {
        cout << c;
    }
    cout<<endl;

    // Make edit
    fileContents = {'T', 'h', 'i', 's', ' ', 'n', 'o', 't', ' ', 't', 'h', 'e', ' ', 't', 'e', 's', 't', ' ', 'f', 'i', 'l', 'e'};
    testFile.write(fileContents);
    vector<char> readFileAfterEdit = testFile.read();

    cout << "After edit: ";
    for (auto c : readFileAfterEdit) {
        cout << c;
    }
    cout << endl;

    TextFile fileNumberOne("fileOne.txt");
    TextFile fileNumberTwo("fileTwo.txt");
    ImageFile imgFileNumberOne("imageFileOne.txt");
    ImageFile imgFileNumberTwo("imageFileTwo.txt");
    BasicDisplayVisitor BDV;

    fileNumberOne.accept(&BDV);
    fileNumberTwo.accept(&BDV);
    imgFileNumberOne.accept(&BDV);
    imgFileNumberTwo.accept(&BDV);

    return 0;
}