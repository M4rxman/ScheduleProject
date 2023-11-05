//
// Created by alex2 on 28.10.2023.
//

#include <iostream>
#include "Schedule.h"

Schedule::Schedule() {
}

Schedule::Schedule(string weekday, string startHour, string duration, string type,  string codeClass) {
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
    this->codeClass = codeClass;
}

string Schedule::getWeekday() {
    return this->weekday;
}

string Schedule::getStartHour() {
    return this->startHour;
}

string Schedule::getDuration() {
    return this->duration;
}

string Schedule::getScheduleType() {
    return this->type;
}

string Schedule::getCodeClass() {
    return this->codeClass;
}

Schedule::Schedule(const vector<Schedule>& timeTable) {

}
