//
// Created by alex2 on 21.10.2023.
//
#include <list>
#include <string>
#include <fstream>
#include "../ClassesStruct/UcCode.h"
#include "DataCollector.h"

#ifndef SCHEDULE_CLASSESPERUCCOLLECTOR_H

using namespace std;


class ClassesPerUc : public DataCollector{
    list<UcCode> cPerUc;

    public:
    void readFile(ifstream& f);
    void addEClassesToUc(string  classCode, string ucCode);

};


#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H
