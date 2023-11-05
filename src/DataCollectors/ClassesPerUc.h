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
    list<UcCode> cPerUc; //ClassesPerUc list

public:
    void readFile(ifstream& f);
    void addClassesToUc(string  classCode, string ucCode);
    void printData();
    UcCode getUcCodebyCode(UcCode ucCode);
    list<UcCode>& getClassesPerUc();
    ClassCode getVerifyClassCode(ClassCode unVerifiedClassCode);

    UcCode *findUcCodeByCode(const string &basicString);
};

#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H
