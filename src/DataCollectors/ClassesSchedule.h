//
// Created by alex2 on 28.10.2023.
//

#ifndef SCHEDULE_CLASSESSCHEDULE_H
#define SCHEDULE_CLASSESSCHEDULE_H
#include "../ClassesStruct/Schedule.h"
#include "../ClassesStruct/UcCode.h"
#include "ClassesPerUc.h"

using namespace std;

class ClassesSchedule {
    list<UcCode> ucCodeClassCode;

public:
    void readFile(ifstream& f, ClassesPerUc& classesPerUc);
    void addClassesToUc(string  classCode, string ucCode);
    void printData(ClassesPerUc& classesPerUc);
    list<UcCode> getUcClassCodes();

};


#endif //SCHEDULE_CLASSESSCHEDULE_H
