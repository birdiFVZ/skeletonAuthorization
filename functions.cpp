//
// Created by Christoph on 05.10.2017.
//
#include <iostream>
#include "functions.h"
#include <cmath>

std::vector<std::string> splitString(
        std::string inputString,
        char delimiter
) {
    std::vector<std::string> returnVector;
    std::string tempString = "";
    for (
            int tag = 0;
            tag < inputString.length();
            tag ++
            ) {
        if (inputString[tag] == delimiter) {
            returnVector.push_back(tempString);
            tempString = "";
        } else {
            tempString += inputString[tag];
        }
    }
    return returnVector;
}

float getd3dDistance(
        std::vector<std::string> first,
        std::vector<std::string> second
) {
    return sqrt(
            pow(stringToFloat(first[2]) - stringToFloat(second[2]),2) +
            pow(stringToFloat(first[3]) - stringToFloat(second[3]),2) +
            pow(stringToFloat(first[4]) - stringToFloat(second[4]),2)
    );
}

float stringToFloat(std::string inputString) {
    int positionTag;
    for (positionTag = 0;
         inputString[positionTag];
         positionTag++) {
        if (inputString[positionTag] == ',') {
            inputString.replace(positionTag,1,".");
        }
    }
    return std::stof(inputString);
}