//
// Created by alex2 on 28.10.2023.
//
#include "Schedule.h"
#include "ClassCode.h"

ClassCode::ClassCode() {}

ClassCode::ClassCode(string leic) {
    this->code = leic;
}

bool ClassCode::operator<(const ClassCode &classCode) const {
    return this->code < classCode.code;
}

void ClassCode::addSchedule(Schedule timeTable) {
    this->schedules.emplace_back(timeTable);
}

string ClassCode::getCode() {
    return this->code;
}

