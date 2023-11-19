//Created by Ethan McCormick on 3/28/2023


#include "mockos/TextFile.h"
#include <iostream>
using namespace std;

int main(){
//    TextFile file("newfile");
    AbstractFile& file = *(new TextFile("newfile"));
    vector<char> writingData = {'T', 'h', 'i', 's', ' ', 'a', ' ', 'n', 'e', 'w', ' ', 'f', 'i', 'l', 'e'};
//    file.write(writingData);
    file.write(writingData);
//    file.read();
    file.read();
    return 0;
}