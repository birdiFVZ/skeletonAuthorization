//
// Created by Christoph on 05.10.2017.
//
#include <iostream>
#include "functions.h"


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