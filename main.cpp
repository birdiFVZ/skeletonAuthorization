#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"

int main() {
    File testFile;
    std::vector<std::vector<std::vector<std::string>>> dataVector;
    //std::cout << "Hello, World!" << testFile.File() << std::endl;
    testFile.calcRelevantData();

    std::vector<std::vector<int>> test;
    std::vector<int> testInt1;
    std::vector<int> testInt10;
    std::vector<int> testInt100;

    testInt1.push_back(1);
    testInt1.push_back(2);
    testInt1.push_back(3);

    testInt10.push_back(10);
    testInt10.push_back(20);
    testInt10.push_back(30);

    testInt100.push_back(100);
    testInt100.push_back(200);
    testInt100.push_back(300);

    test.push_back(testInt1);
    test.push_back(testInt10);
    test.push_back(testInt100);

    test.erase(test.begin());

    for (int i = 0; i < test.size(); i++){
        for (int j = 0; j < test[i].size(); j++) {
            std::cout << test[i][j] << std::endl;
        }
    }

    return 0;
}