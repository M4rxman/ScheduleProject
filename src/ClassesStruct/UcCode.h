//
// Created by alex2 on 26.10.2023.
//
#include <string>
#include <list>
#ifndef SCHEDULE_UCCODE_H
#define SCHEDULE_UCCODE_H

using namespace std;


class UcCode {


public:
    string ucCode;
    list<string> classCode;
    UcCode(string _ucCode, list<string> classCode);
    void SetUcCode(string ucCode);
    string GetUcCode();
    bool operator<(const UcCode &code) const;
    void addClassCOde(string leic);

};

#endif //SCHEDULE_UCCODE_H
