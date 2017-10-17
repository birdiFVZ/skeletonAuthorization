#ifndef TESTPROJECT_FILE_H
#define TESTPROJECT_FILE_H

struct bodyProperty {
    std::string name;
    float value;
};

class File {
    public:
        void buildBodyVector();
        void buildRawDataVector();
        File(std::string inputFile);
    private:
        std::vector<std::vector<std::vector<std::string>>> rawDataVector;
        std::vector<std::vector<bodyProperty>> bodyVector;
};



#endif //TESTPROJECT_FILE_H
