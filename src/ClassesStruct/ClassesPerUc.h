//
// Created by alex2 on 21.10.2023.
//
#include <string>
#ifndef SCHEDULE_CLASSESPERUCCOLLECTOR_H
#define SCHEDULE_CLASSESPERUCCOLLECTOR_H

using namespace std;


class ClassesPerUc {
    string _ucCode;
    string _classCode;

    public:
    ClassesPerUc();
    ClassesPerUc(string ucCode,string classCode);
    void SetUcCode(string ucCode);
    void SetClassCode(string classCode);
    string GetUcCode();
    string GetClassCode();
    bool operator < (const ClassesPerUc& code) const;



};


#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H
