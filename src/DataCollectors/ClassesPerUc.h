//
// Created by alex2 on 21.10.2023.
//
#include <list>
#include <string>
#include <fstream>
#include "../ClassesStruct/UcCode.h"

#ifndef SCHEDULE_CLASSESPERUCCOLLECTOR_H

using namespace std;


class ClassesPerUc {
    list<UcCode> cPerUc;

public:
    void readFile(ifstream& f);
    void addClassesToUc(string  classCode, string ucCode);
    void writeFile();
};

#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H