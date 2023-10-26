//
// Created by alex2 on 21.10.2023.
//
#include <list>
#include <string>
#ifndef SCHEDULE_CLASSESPERUCCOLLECTOR_H
#define SCHEDULE_CLASSESPERUCCOLLECTOR_H

using namespace std;


class ClassesPerUc {
    string ucCode;
    list<string> classCode;

    public:
    ClassesPerUc();
    ClassesPerUc(string ucCode,string classCode);
    void SetUcCode(string ucCode);
    string GetUcCode();
    bool operator < (const ClassesPerUc& code) const;



};


#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H
