#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"
#include "functions.h"

#define bodyPoints 25

File::File(std::string inputFile) {
    std::string line;
    std::vector<std::vector<std::string>> tempDataVector;
    char delimiter = ';';
    std::ifstream myFile(inputFile);
    int lineAmount = 0;
    if (myFile.is_open()) {
        while (getline (myFile,line)) {
            lineAmount +=1;
            tempDataVector.push_back(
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
                        tempDataVector[rawDataTag][bodyPointDataTag]
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
        bodyTag < File::rawDataVector.size();
        bodyTag++) {
        for(bodyPointTag = 0;
            bodyPointTag < File::rawDataVector[bodyTag].size();
            bodyPointTag++) {
            if (File::rawDataVector[bodyTag][bodyPointTag][5] != "Tracked") {
                File::rawDataVector.erase(File::rawDataVector.begin() + bodyTag);
                bodyTag--;
                break;
            }
        }
    }

}

void File::buildBodyVector() {

    int bodyTag;
    for (bodyTag = 0;
         bodyTag < File::rawDataVector.size();
         bodyTag++) {
        bodyVector.push_back(std::vector<bodyProperty>());
        std::vector<bodyProperty> bodyPointProperty;
        int propertyTag = 0;
        bodyProperty forarmLeft;
        forarmLeft.name = File::properties[propertyTag];
        forarmLeft.value =getd3dDistance(
                File::rawDataVector[bodyTag][6],
                File::rawDataVector[bodyTag][5]
        );
        bodyPointProperty.push_back(forarmLeft);
        propertyTag++;

        bodyProperty upperarmLeft;
        upperarmLeft.name = File::properties[propertyTag];
        upperarmLeft.value =getd3dDistance(
                File::rawDataVector[bodyTag][5],
                File::rawDataVector[bodyTag][4]
        );
        bodyPointProperty.push_back(upperarmLeft);
        propertyTag++;

        bodyProperty shoulderHalfLeft;
        shoulderHalfLeft.name = File::properties[propertyTag];
        shoulderHalfLeft.value =getd3dDistance(
                File::rawDataVector[bodyTag][4],
                File::rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(shoulderHalfLeft);
        propertyTag++;

        bodyProperty neck;
        neck.name = File::properties[propertyTag];
        neck.value =getd3dDistance(
                File::rawDataVector[bodyTag][2],
                File::rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(neck);
        propertyTag++;

        bodyProperty shoulderHalfRight;
        shoulderHalfRight.name = File::properties[propertyTag];
        shoulderHalfRight.value =getd3dDistance(
                File::rawDataVector[bodyTag][8],
                File::rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(shoulderHalfRight);
        propertyTag++;

        bodyProperty upperarmRight;
        upperarmRight.name = File::properties[propertyTag];
        upperarmRight.value =getd3dDistance(
                File::rawDataVector[bodyTag][9],
                File::rawDataVector[bodyTag][8]
        );
        bodyPointProperty.push_back(upperarmRight);
        propertyTag++;

        bodyProperty forarmRight;
        forarmRight.name = File::properties[propertyTag];
        forarmRight.value =getd3dDistance(
                File::rawDataVector[bodyTag][10],
                File::rawDataVector[bodyTag][9]
        );
        bodyPointProperty.push_back(forarmRight);
        propertyTag++;

        bodyProperty shoulder;
        shoulder.name = File::properties[propertyTag];
        shoulder.value =getd3dDistance(
                File::rawDataVector[bodyTag][4],
                File::rawDataVector[bodyTag][8]
        );
        bodyPointProperty.push_back(shoulder);
        propertyTag++;

        bodyProperty upperBody;
        upperBody.name = File::properties[propertyTag];
        upperBody.value =getd3dDistance(
                File::rawDataVector[bodyTag][1],
                File::rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(upperBody);
        propertyTag++;

        bodyProperty hip;
        hip.name = File::properties[propertyTag];
        hip.value =getd3dDistance(
                File::rawDataVector[bodyTag][12],
                File::rawDataVector[bodyTag][16]
        );
        bodyPointProperty.push_back(hip);
        propertyTag++;

        bodyProperty lowerBody;
        lowerBody.name = File::properties[propertyTag];
        lowerBody.value =getd3dDistance(
                File::rawDataVector[bodyTag][1],
                File::rawDataVector[bodyTag][0]
        );
        bodyPointProperty.push_back(lowerBody);
        propertyTag++;

        bodyProperty body;
        body.name = File::properties[propertyTag];
        body.value =getd3dDistance(
                File::rawDataVector[bodyTag][0],
                File::rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(body);
        propertyTag++;

        bodyProperty lowerLegLeft;
        lowerLegLeft.name = File::properties[propertyTag];
        lowerLegLeft.value =getd3dDistance(
                File::rawDataVector[bodyTag][14],
                File::rawDataVector[bodyTag][13]
        );
        bodyPointProperty.push_back(lowerLegLeft);
        propertyTag++;

        bodyProperty upperLegLeft;
        upperLegLeft.name = File::properties[propertyTag];
        upperLegLeft.value =getd3dDistance(
                File::rawDataVector[bodyTag][13],
                File::rawDataVector[bodyTag][12]
        );
        bodyPointProperty.push_back(upperLegLeft);
        propertyTag++;

        bodyProperty upperLegRight;
        upperLegRight.name = File::properties[propertyTag];
        upperLegRight.value =getd3dDistance(
                File::rawDataVector[bodyTag][17],
                File::rawDataVector[bodyTag][16]
        );
        bodyPointProperty.push_back(upperLegRight);
        propertyTag++;

        bodyProperty lowerLegRight;
        lowerLegRight.name = File::properties[propertyTag];
        lowerLegRight.value =getd3dDistance(
                File::rawDataVector[bodyTag][14],
                File::rawDataVector[bodyTag][17]
        );
        bodyPointProperty.push_back(lowerLegRight);

        bodyVector[bodyTag] = bodyPointProperty;
    }

}
