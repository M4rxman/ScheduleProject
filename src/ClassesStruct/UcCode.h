//
// Created by alex2 on 26.10.2023.
//
#include <string>
#include <list>
#include "ClassCode.h"
#ifndef SCHEDULE_UCCODE_H
#define SCHEDULE_UCCODE_H

using namespace std;


class UcCode {
    string ucCode;
    list<ClassCode> classCode;

public:

    UcCode(string _ucCode, list<ClassCode> classCode);
    void SetUcCode(string ucCode);
    string getUcCode();
    list<ClassCode>& getClassCodes();
    bool operator<(const UcCode &code) const;
    void addClassCode(string leic);

};

#endif //SCHEDULE_UCCODE_H
