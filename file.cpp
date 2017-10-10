#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <wtypes.h>
#include "file.h"
#include "functions.h"


struct valueElement {
    std::string Name_;
    DATE Time_;
    float Value1_;
    float Value2_;
    float Value3_;
    bool status;
};

struct dataPoint {
    std::string SpineBase_;
    std::string SpineMid_;
    std::string Neck_;
    std::string Head_;
    std::string ShoulderLeft_;
    std::string ElbowLeft_;
    std::string WristLeft_;
    std::string HandLeft_;
    std::string ShoulderRight_;
    std::string ElbowRight_;
    std::string WristRight_;
    std::string HandRight_;
    std::string HipLeft_;
    std::string KneeLeft_;
    std::string AnkleLeft_;
    std::string FootLeft_;
    std::string HipRight_;
    std::string KneeRight_;
    std::string AnkleRight_;
    std::string FootRight_;
    std::string SpineShoulder_;
    std::string HandTipLeft_;
    std::string ThumbLeft_;
    std::string HandTipRight_;
    std::string ThumbRight_;
};

void file::readFile() {
    std::string line;
    std::vector<std::string> lineVector;
    std::vector<std::vector<std::string>> dataVector;
    std::vector<dataPoint> bodyData;
    char delimiter = ';';
    //std::ifstream myFile("C:\\Users\\Birdi\\CLionProjects\\skeletonAuthorization\\data\\skeletonDataOneBody.txt");
    std::ifstream myFile("C:\\Users\\Christoph\\CLionProjects\\skeletonAuthorization\\data\\skeletonDataOneBody.txt");
    int lineAmount = 0;
    if (myFile.is_open()) {
        while (getline (myFile,line)) {
            lineAmount +=1;
            dataVector.push_back(
                    splitString(line, delimiter)
            );
        }
        myFile.close();
    }

    std::cout << lineAmount << std::endl;
    std::cout << "==============================" << std::endl;

    int dataTag;
    int bodyTag;
    for (bodyTag = 0; bodyTag < lineAmount; bodyTag++) {
        for (dataTag = 0; dataTag < 24; dataTag++ ) {
            std::cout << dataVector[bodyTag][dataTag] << " - ";
        }
        std::cout << "==============================" << std::endl;
    }


    // std::cout << dataVector[0][0] << std::endl;


}
