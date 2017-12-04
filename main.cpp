#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include "functions.h"

#define bodyPoints 25

struct mean {
    int amount;
    float sum;
};

struct bodyProperty {
    std::string name;
    float value;
};
struct propertyData {
    std::string name;
    std::vector<float> values;
};
struct statisticData {
    std::string name;
    int amountDatapoints;
    int amountOutliers;
    float min;
    float max;
    float sum;
    float median;
    float mean;
    float lowerQuartile;
    float upperQuartile;
    float quartileDistance;
    float lowerWhisker;
    float upperWhisker;
};

int main() {
    bool writeOutput = false;
    void buildBodyVector();
    void buildRawDataVector();
    std::vector<std::string> properties = {
            "forearmLeft",
            "upperarmLeft",
            "shoulderHalfLeft",
            "neck",
            "shoulderHalfRight",
            "upperarmRight",
            "forearmRight",
            "shoulder",
            "upperBody",
            "hip",
            "lowerBody",
            "body",
            "lowerLegLeft",
            "upperLegLeft",
            "upperLegRight",
            "lowerLegRight"
    };
    std::vector<std::vector<std::vector<std::string>>> rawDataVector;
    std::vector<std::vector<bodyProperty>> bodyVector;
    std::vector<statisticData> statisticVector;
    std::vector<propertyData> propertyDataVector;

    //init statisticVector & propertyDataVector & mean
    mean z;
    z.amount = 0;
    z.sum = 0;
    for (int tag = 0;
         tag < properties.size();
         tag++) {
        statisticVector.push_back(statisticData());
        statisticData statistics;
        statistics.name = properties[tag];
        statistics.amountDatapoints = 0;
        statistics.amountOutliers = 0;
        statistics.min = INFINITY;
        statistics.max = -INFINITY;
        statistics.sum = 0;
        statistics.median = 0;
        statistics.mean = 0;
        statistics.lowerQuartile = 0;
        statistics.upperQuartile = 0;
        statistics.quartileDistance = 0;
        statistics.lowerWhisker = 0;
        statistics.upperWhisker = 0;
        statisticVector[tag] = statistics;

        propertyDataVector.push_back(propertyData());
        propertyData property;
        property.name = properties[tag];
        propertyDataVector[tag] = property;
    }

    std::string fileName = "cvNoMoving";


    //#######################################################################
    // read File
    //#######################################################################
    std::string inputFile("/home/birdi/CLionProjects/skeletonAuthorization04122017/data/" + fileName + ".txt");
    //std::string inputFile("C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization20112017\\data\\"+fileName+".txt");
    std::string line;
    std::vector<std::vector<std::string>> tempDataVector;
    char delimiter = ';';
    std::ifstream myFile;
    myFile.open(inputFile);
    int lineAmount = 0;

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            lineAmount += 1;
            tempDataVector.push_back(
                    splitString(line, delimiter)
            );
        }
        myFile.close();
    }

    // build Array
    int bodyPointDataTag;
    int bodyTag;
    int bodyAmount = lineAmount / bodyPoints;
    int bodyPointTag;
    int rawDataTag = 0;
    for (bodyTag = 0; bodyTag < bodyAmount; bodyTag++) {
        rawDataVector.push_back(std::vector<std::vector<std::string>>());
        for (bodyPointTag = 0; bodyPointTag < bodyPoints; bodyPointTag++) {
            rawDataVector[bodyTag].push_back(std::vector<std::string>());
            for (bodyPointDataTag = 0; bodyPointDataTag < 6; bodyPointDataTag++) {
                rawDataVector[bodyTag][bodyPointTag].push_back(
                        tempDataVector[rawDataTag][bodyPointDataTag]
                );
            }
            rawDataTag++;
        }
    }

    //delate untracked points
    for (bodyTag = 0;
         bodyTag < rawDataVector.size();
         bodyTag++) {
        for (bodyPointTag = 0;
             bodyPointTag < rawDataVector[bodyTag].size();
             bodyPointTag++) {
            if (rawDataVector[bodyTag][bodyPointTag][5] != "Tracked") {
                rawDataVector.erase(rawDataVector.begin() + bodyTag);
                bodyTag--;
                break;
            }
        }
    }

    //build bodyArray
    for (bodyTag = 0;
         bodyTag < rawDataVector.size();
         bodyTag++) {
        bodyVector.push_back(std::vector<bodyProperty>());
        std::vector<bodyProperty> bodyPointProperty;
        int propertyTag = 0;
        bodyProperty forarmLeft;
        forarmLeft.name = properties[propertyTag];
        forarmLeft.value = getd3dDistance(
                rawDataVector[bodyTag][6],
                rawDataVector[bodyTag][5]
        );
        bodyPointProperty.push_back(forarmLeft);
        propertyDataVector[propertyTag].values.push_back(forarmLeft.value);
        propertyTag++;

        bodyProperty upperarmLeft;
        upperarmLeft.name = properties[propertyTag];
        upperarmLeft.value = getd3dDistance(
                rawDataVector[bodyTag][5],
                rawDataVector[bodyTag][4]
        );
        bodyPointProperty.push_back(upperarmLeft);
        propertyDataVector[propertyTag].values.push_back(upperarmLeft.value);
        propertyTag++;

        bodyProperty shoulderHalfLeft;
        shoulderHalfLeft.name = properties[propertyTag];
        shoulderHalfLeft.value = getd3dDistance(
                rawDataVector[bodyTag][4],
                rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(shoulderHalfLeft);
        propertyDataVector[propertyTag].values.push_back(shoulderHalfLeft.value);
        propertyTag++;

        bodyProperty neck;
        neck.name = properties[propertyTag];
        neck.value = getd3dDistance(
                rawDataVector[bodyTag][2],
                rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(neck);
        propertyDataVector[propertyTag].values.push_back(neck.value);
        propertyTag++;

        bodyProperty shoulderHalfRight;
        shoulderHalfRight.name = properties[propertyTag];
        shoulderHalfRight.value = getd3dDistance(
                rawDataVector[bodyTag][8],
                rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(shoulderHalfRight);
        propertyDataVector[propertyTag].values.push_back(shoulderHalfRight.value);
        propertyTag++;

        bodyProperty upperarmRight;
        upperarmRight.name = properties[propertyTag];
        upperarmRight.value = getd3dDistance(
                rawDataVector[bodyTag][9],
                rawDataVector[bodyTag][8]
        );
        bodyPointProperty.push_back(upperarmRight);
        propertyDataVector[propertyTag].values.push_back(upperarmRight.value);
        propertyTag++;

        bodyProperty forarmRight;
        forarmRight.name = properties[propertyTag];
        forarmRight.value = getd3dDistance(
                rawDataVector[bodyTag][10],
                rawDataVector[bodyTag][9]
        );
        bodyPointProperty.push_back(forarmRight);
        propertyDataVector[propertyTag].values.push_back(forarmRight.value);
        propertyTag++;

        bodyProperty shoulder;
        shoulder.name = properties[propertyTag];
        shoulder.value = getd3dDistance(
                rawDataVector[bodyTag][4],
                rawDataVector[bodyTag][8]
        );
        bodyPointProperty.push_back(shoulder);
        propertyDataVector[propertyTag].values.push_back(shoulder.value);
        propertyTag++;

        bodyProperty upperBody;
        upperBody.name = properties[propertyTag];
        upperBody.value = getd3dDistance(
                rawDataVector[bodyTag][1],
                rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(upperBody);
        propertyDataVector[propertyTag].values.push_back(upperBody.value);
        propertyTag++;

        bodyProperty hip;
        hip.name = properties[propertyTag];
        hip.value = getd3dDistance(
                rawDataVector[bodyTag][12],
                rawDataVector[bodyTag][16]
        );
        bodyPointProperty.push_back(hip);
        propertyDataVector[propertyTag].values.push_back(hip.value);
        propertyTag++;

        bodyProperty lowerBody;
        lowerBody.name = properties[propertyTag];
        lowerBody.value = getd3dDistance(
                rawDataVector[bodyTag][1],
                rawDataVector[bodyTag][0]
        );
        bodyPointProperty.push_back(lowerBody);
        propertyDataVector[propertyTag].values.push_back(lowerBody.value);
        propertyTag++;

        bodyProperty body;
        body.name = properties[propertyTag];
        body.value = getd3dDistance(
                rawDataVector[bodyTag][0],
                rawDataVector[bodyTag][20]
        );
        bodyPointProperty.push_back(body);
        propertyDataVector[propertyTag].values.push_back(body.value);
        propertyTag++;

        bodyProperty lowerLegLeft;
        lowerLegLeft.name = properties[propertyTag];
        lowerLegLeft.value = getd3dDistance(
                rawDataVector[bodyTag][14],
                rawDataVector[bodyTag][13]
        );
        bodyPointProperty.push_back(lowerLegLeft);
        propertyDataVector[propertyTag].values.push_back(lowerLegLeft.value);
        propertyTag++;

        bodyProperty upperLegLeft;
        upperLegLeft.name = properties[propertyTag];
        upperLegLeft.value = getd3dDistance(
                rawDataVector[bodyTag][13],
                rawDataVector[bodyTag][12]
        );
        bodyPointProperty.push_back(upperLegLeft);
        propertyDataVector[propertyTag].values.push_back(upperLegLeft.value);
        propertyTag++;

        bodyProperty upperLegRight;
        upperLegRight.name = properties[propertyTag];
        upperLegRight.value = getd3dDistance(
                rawDataVector[bodyTag][17],
                rawDataVector[bodyTag][16]
        );
        bodyPointProperty.push_back(upperLegRight);
        propertyDataVector[propertyTag].values.push_back(upperLegRight.value);
        propertyTag++;

        bodyProperty lowerLegRight;
        lowerLegRight.name = properties[propertyTag];
        lowerLegRight.value = getd3dDistance(
                rawDataVector[bodyTag][14],
                rawDataVector[bodyTag][17]
        );
        bodyPointProperty.push_back(lowerLegRight);
        propertyDataVector[propertyTag].values.push_back(lowerLegRight.value);

        std::cout << stringToFloat(rawDataVector[bodyTag][1][4]) << std::endl;
        z.sum += stringToFloat(rawDataVector[bodyTag][1][4]);
        z.amount++;
        bodyVector[bodyTag] = (bodyPointProperty);
    }

    //write calcData

        std::string outputFile = "/home/birdi/CLionProjects/skeletonAuthorization04122017/calcData/" + fileName + ".csv";
        //std::string outputFile =
                //"C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization20112017\\calcData\\" + fileName + ".csv";
        std::ofstream file;
        file.open(outputFile, std::ofstream::out);
        file << "property" << ";" << "value" << std::endl;
        for (bodyTag = 0;
             bodyTag < bodyVector.size();
             bodyTag++
                ) {
            for (bodyPointTag = 0;
                 bodyPointTag < bodyVector[bodyTag].size();
                 bodyPointTag++) {
                file << bodyVector[bodyTag][bodyPointTag].name << ';' <<
                        bodyVector[bodyTag][bodyPointTag].value << std::endl;
            }

        }


        file.close();


    //build sortArray
    int propertyTag;
    int propertyValueTag;

    float sortValues
    [propertyDataVector.size()]
    [propertyDataVector[0].values.size()];
    for (propertyTag = 0;
         propertyTag < propertyDataVector.size();
         propertyTag++) {
        for (propertyValueTag = 0;
             propertyValueTag < propertyDataVector[propertyTag].values.size();
             propertyValueTag++) {
            sort(propertyDataVector[propertyTag].values.begin(),
                 propertyDataVector[propertyTag].values.end());
        }
    }

    //build statistics
    for (propertyTag = 0;
         propertyTag < bodyVector[0].size();
         propertyTag++) {
        int lowerQuartilPosition =
                0.25 * (propertyDataVector[propertyTag].values.size() + 1);
        int medianPosition =
                0.5 * (propertyDataVector[propertyTag].values.size() + 1);
        int upperQuartilPosition =
                0.75 * (propertyDataVector[propertyTag].values.size() + 1);
        statisticVector[propertyTag].min =
            propertyDataVector[propertyTag].values[0];
        statisticVector[propertyTag].max =
            propertyDataVector[propertyTag].values
            [propertyDataVector[propertyTag].values.size() - 1];
        statisticVector[propertyTag].amountDatapoints =
            propertyDataVector[propertyTag].values.size();
        statisticVector[propertyTag].lowerQuartile =
            propertyDataVector[propertyTag].values[lowerQuartilPosition];
        statisticVector[propertyTag].median =
            propertyDataVector[propertyTag].values[medianPosition];
        statisticVector[propertyTag].upperQuartile =
            propertyDataVector[propertyTag].values[upperQuartilPosition];
        statisticVector[propertyTag].quartileDistance =
            propertyDataVector[propertyTag].values[upperQuartilPosition] -
            propertyDataVector[propertyTag].values[lowerQuartilPosition];
        float tempLowerWhisker =
            statisticVector[propertyTag].lowerQuartile -
            1.5 * statisticVector[propertyTag].quartileDistance;
        float tempUpperWhisker =
                statisticVector[propertyTag].upperQuartile +
                1.5 * statisticVector[propertyTag].quartileDistance;
        for(propertyValueTag=0;
            propertyValueTag < propertyDataVector[propertyTag].values.size();
            propertyValueTag++) {
            statisticVector[propertyTag].sum +=
                    propertyDataVector[propertyTag].values[propertyValueTag];
            if (
                propertyDataVector[propertyTag].values[propertyValueTag] <
                tempUpperWhisker
                ) {
                statisticVector[propertyTag].upperWhisker =
                    propertyDataVector[propertyTag].values[propertyValueTag];
            } else {
                statisticVector[propertyTag].amountOutliers++;
            }

            if (
                propertyDataVector[propertyTag].values
                    [propertyDataVector[propertyTag].values.size() - propertyValueTag - 1] >
                tempLowerWhisker) {
                statisticVector[propertyTag].lowerWhisker =
                        propertyDataVector[propertyTag].values
                        [propertyDataVector[propertyTag].values.size() - propertyValueTag - 1];
            } else {
                statisticVector[propertyTag].amountOutliers++;
            }
        }
        statisticVector[propertyTag].mean =
                statisticVector[propertyTag].sum /
                statisticVector[propertyTag].amountDatapoints;
    }

    //write Output & file
    if (writeOutput) {
        //std::string outputFile = "/home/birdi/CLionProjects/skeletonAuthorization/output/resultAll.csv";
        std::string outputFile =
                "C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization20112017\\output\\" + fileName + ".csv";
        std::ofstream file;
        file.open(outputFile, std::ofstream::out);
        file << "property" << ";" << "statistic" << ";" << "value" << std::endl;
        for (propertyTag = 0;
             propertyTag < statisticVector.size();
             propertyTag++
                ) {
            std::cout << statisticVector[propertyTag].name << std::endl;
            std::cout << "lowerWhisker: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].lowerWhisker << std::endl;
            file << statisticVector[propertyTag].name << ";" << "lowerWhisker" << ";"
                 << statisticVector[propertyTag].lowerWhisker << std::endl;
            std::cout << "lowerQuartile: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].lowerQuartile << std::endl;
            file << statisticVector[propertyTag].name << ";" << "lowerQuartile" << ";"
                 << statisticVector[propertyTag].lowerQuartile << std::endl;
            std::cout << "median: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].median << std::endl;
            file << statisticVector[propertyTag].name << ";" << "median" << ";" << statisticVector[propertyTag].median
                 << std::endl;
            std::cout << "upperQuartile: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].upperQuartile << std::endl;
            file << statisticVector[propertyTag].name << ";" << "upperQuartile" << ";"
                 << statisticVector[propertyTag].upperQuartile << std::endl;
            std::cout << "upperWhisker: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].upperWhisker << std::endl;
            file << statisticVector[propertyTag].name << ";" << "upperWhisker" << ";"
                 << statisticVector[propertyTag].upperWhisker << std::endl;
            std::cout << "minValue: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].min << std::endl;
            file << statisticVector[propertyTag].name << ";" << "minValue" << ";" << statisticVector[propertyTag].min
                 << std::endl;
            std::cout << "maxValue: " << "\t\t\t\t\t\t" << statisticVector[propertyTag].max << std::endl;
            file << statisticVector[propertyTag].name << ";" << "maxValue" << ";" << statisticVector[propertyTag].max
                 << std::endl;
            std::cout << "amountDatapoints: " << "\t\t\t\t\t" << statisticVector[propertyTag].amountDatapoints
                      << std::endl;
            file << statisticVector[propertyTag].name << ";" << "amountDataPoints" << ";"
                 << statisticVector[propertyTag].amountDatapoints << std::endl;
            std::cout << "amountOutliers: " << "\t\t\t\t\t" << statisticVector[propertyTag].amountOutliers << std::endl;
            file << statisticVector[propertyTag].name << ";" << "amountOutliers" << ";"
                 << statisticVector[propertyTag].amountOutliers << std::endl;
            std::cout << "sum: " << "\t\t\t\t\t\t\t" << statisticVector[propertyTag].sum << std::endl;
            file << statisticVector[propertyTag].name << ";" << "sum" << ";" << statisticVector[propertyTag].sum
                 << std::endl;
            std::cout << "mean: " << "\t\t\t\t\t\t\t" << statisticVector[propertyTag].mean << std::endl;
            file << statisticVector[propertyTag].name << ";" << "mean" << ";" << statisticVector[propertyTag].mean
                 << std::endl;
            std::cout << "quartileDistance: " << "\t\t\t\t\t" << statisticVector[propertyTag].quartileDistance
                      << std::endl;
            file << statisticVector[propertyTag].name << ";" << "quartileDistance" << ";"
                 << statisticVector[propertyTag].quartileDistance << std::endl;
            std::cout << "************************************************************************************"
                      << std::endl;
        }


        file.close();
    }

    std::cout << "done" << std::endl;


    return 0;
}

