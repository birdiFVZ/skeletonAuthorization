#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"

int main() {
    File testFile("C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization\\data\\skeletonData5000.txt");
    //File testFile("C:\\Users\\Birdi\\CLionProjects\\skeletonAuthorization\\data\\skeletonDataOneBody.txt");

    //std::cout << "Hello, World!" << testFile.File() << std::endl;
    testFile.buildRawDataVector();
    testFile.buildBodyVector();

    return 0;
}