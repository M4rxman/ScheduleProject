//
// Created by alex2 on 28.10.2023.
//

#ifndef SCHEDULE_CLASSCODE_H
#define SCHEDULE_CLASSCODE_H
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "Schedule.h"

using namespace std;


class ClassCode {

    string code;
    vector<Schedule> schedules; // work to be done


public:
    ClassCode();
    ClassCode(string leic);
    void addSchedule(Schedule timeTable);
    string getCode();
    vector<Schedule> getSchedule();
    bool operator<(const ClassCode &classCode) const;

    bool operator==(const ClassCode &other) const {
        return this->code == other.code; // You might need to consider Schedule objects in your comparison
    }

    ClassCode(list <ClassCode> code);
};

#endif //SCHEDULE_CLASSCODE_H
