//
// Created by alex2 on 26.10.2023.
//
#include <string>
#include <list>
#ifndef SCHEDULE_UCCODE_H
#define SCHEDULE_UCCODE_H

using namespace std;


class UcCodeClassCode {


public:
    string ucCode;
    list<string> classCode;
    UcCodeClassCode(string _ucCode, list<string> classCode);
    void SetUcCode(string ucCode);
    string GetUcCode();
    bool operator<(const UcCodeClassCode &code) const;
    void addClassCode(string leic);

};

#endif //SCHEDULE_UCCODE_H
