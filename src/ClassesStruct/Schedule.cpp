//
// Created by alex2 on 28.10.2023.
//

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
