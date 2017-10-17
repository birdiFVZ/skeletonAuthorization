#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"
#include "functions.h"

#define bodyPoints 25

File::File(std::string inputFile) {
    std::string line;
    std::vector<std::string> lineVector;
    std::vector<std::vector<std::string>> rawDataVector;
    char delimiter = ';';
    std::ifstream myFile(inputFile);
    int lineAmount = 0;
    if (myFile.is_open()) {
        while (getline (myFile,line)) {
            lineAmount +=1;
            rawDataVector.push_back(
                    splitString(line, delimiter)
            );
        }
        myFile.close();
    }

    int bodyPointDataTag;
    int bodyTag;
    int bodyAmount = lineAmount / bodyPoints;
    int bodyPointTag;
    int rawDataTag = 0;
    for (bodyTag = 0; bodyTag < bodyAmount; bodyTag++) {
        File::rawDataVector.push_back(std::vector<std::vector<std::string>>());
        for(bodyPointTag = 0; bodyPointTag < bodyPoints; bodyPointTag++) {
            File::rawDataVector[bodyTag].push_back(std::vector<std::string>());
            for (bodyPointDataTag = 0; bodyPointDataTag < 6; bodyPointDataTag++) {
                File::rawDataVector[bodyTag][bodyPointTag].push_back(
                        rawDataVector[rawDataTag][bodyPointDataTag]
                );
            }
            rawDataTag++;
        }
    }
}

void File::buildRawDataVector() {
    int bodyTag;
    int bodyPointTag;
    for(bodyTag = 0;
        bodyTag < rawDataVector.size();
        bodyTag++) {
        for(bodyPointTag = 0;
            bodyPointTag < rawDataVector[bodyTag].size();
            bodyPointTag++) {
            if (rawDataVector[bodyTag][bodyPointTag][5] != "Tracked") {
                rawDataVector.erase(rawDataVector.begin() + bodyTag);
                bodyTag--;
                break;
            }
        }
    }
}

void File::buildBodyVector() {
    //TODO hier weiter machen body vector!!!

    int bodyTag;
    int bodyPointTag;
    for(bodyTag = 0;
        bodyTag < 2;
        bodyTag++) {
        bodyVector.push_back(std::vector<bodyProperty>());

        bodyVector[bodyTag].push_back(bodyProperty());
        bodyProperty test;
        test.name = "name";
        test.value = 1.234;
        bodyVector[bodyTag].push_back(test);

    }

    std::cout << bodyVector[0][0].name;

}
