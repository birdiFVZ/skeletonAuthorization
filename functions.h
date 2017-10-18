#include <vector>

#ifndef TESTPROJECT_FUNCTIONS_H
#define TESTPROJECT_FUNCTIONS_H

std::vector<std::string> splitString(
        std::string inputString,
        char delimiter
);

float getd3dDistance(
        std::vector<std::string> first,
        std::vector<std::string> second
);

float stringToFloat(std::string inputString);

#endif //TESTPROJECT_FUNCTIONS_H
