//
// Created by alex2 on 28.10.2023.
//

#ifndef SCHEDULE_SCHEDULE_H
#define SCHEDULE_SCHEDULE_H
#include <string>
#include <vector>

using namespace std;

class Schedule {
    string weekday;
    string startHour;
    string duration;
    string type;
    string codeClass;

public:
    Schedule();
    Schedule(string weekday, string startHour, string duration, string type,  string codeClass);
    string getWeekday();
    string getStartHour();
    string getDuration();
    string getScheduleType();
    string getCodeClass();

    Schedule(const vector<Schedule>& vector1);
};



#endif //SCHEDULE_SCHEDULE_H
