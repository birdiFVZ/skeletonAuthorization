#ifndef TESTPROJECT_FILE_H
#define TESTPROJECT_FILE_H


class File {
    public:
        void calcRelevantData();
        File();
    private:
        std::vector<std::vector<std::vector<std::string>>> dataVector;
};



#endif //TESTPROJECT_FILE_H
