#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"
#include "functions.h"

#define bodyPoints 25

File::File(void) {
    std::string line;
    std::vector<std::string> lineVector;
    std::vector<std::vector<std::string>> rawDataVector;
    char delimiter = ';';
    //std::ifstream myFile("C:\\Users\\Birdi\\CLionProjects\\skeletonAuthorization\\data\\skeletonDataOneBody.txt");
    std::ifstream myFile("C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization\\data\\skeletonData200.txt");
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
        File::dataVector.push_back(std::vector<std::vector<std::string>>());
        for(bodyPointTag = 0; bodyPointTag < bodyPoints; bodyPointTag++) {
            File::dataVector[bodyTag].push_back(std::vector<std::string>());
            for (bodyPointDataTag = 0; bodyPointDataTag < 6; bodyPointDataTag++) {
                File::dataVector[bodyTag][bodyPointTag].push_back(
                        rawDataVector[rawDataTag][bodyPointDataTag]
                );
            }
            rawDataTag++;
        }
    }
}

void File::calcRelevantData() {
    std::cout << "data[0][0][0]" << dataVector[0][0][0] << std::endl;
    std::cout << "dataVector.size(): " << dataVector.size() << std::endl;
    std::cout << "dataVector[0].size(): " << dataVector[0].size() << std::endl;
    std::cout << "dataVector[0][0].size(): " << dataVector[0][0].size() << std::endl;


    int bodyTag;
    int bodyPointTag;
    int bodyPointDataTag;
    for(bodyTag = 0;
        bodyTag < dataVector.size();
        bodyTag++) {
        for(bodyPointTag = 0;
            bodyPointTag < dataVector[bodyTag].size();
            bodyPointTag++) {
            std::cout << "result: " << dataVector[bodyTag][bodyPointTag][5]<< std::endl;
            std::cout << "bodyPoint" << std::endl;
            for(bodyPointDataTag = 0;
                bodyPointDataTag < dataVector[bodyTag][bodyPointTag].size();
                bodyPointDataTag++) {

                    std::string data =
                            dataVector[bodyTag][bodyPointTag][bodyPointDataTag];
                    if(data != "Tracked") {
                        std::cout << "data: " << data << std::endl;
                    }

            }
        }
    }
}
