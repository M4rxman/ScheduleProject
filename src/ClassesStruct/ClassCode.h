//
// Created by alex2 on 28.10.2023.
//

#ifndef SCHEDULE_CLASSCODE_H
#define SCHEDULE_CLASSCODE_H
#include <string>
#include <vector>
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
    bool operator<(const ClassCode &classCode) const;

};

#endif //SCHEDULE_CLASSCODE_H
