#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include "UcCode.h"
#include "ClassesPerUc.h"
#include <vector>

using namespace std;

class Student {
    string studentCode;
    string studentName;
    list<UcCode> ucCode;

public:
    Student();
    Student(string studentCode, string studentName, list<UcCode> ucCode);
    void setStudentCode(string studentCode);
    void setStudentName(string studentName);
    void setUcCode( list<UcCode> ucCode);
    void addUcCode(UcCode newUcCode);

    string getStudentCode();
    string getStudentName();
    list<UcCode> getUcCodelist();
    list<ClassCode> getClassCodeByUcCode(UcCode givenUcCode);
    vector<Schedule> getScheduleByClassCode(ClassCode givenClassCode);

    bool operator < (const Student& code) const;

    vector<Schedule> getSchedule();

    void removeUcCode(UcCode code);


    int timeToMinutes(const string &time);
    int durationToMinutes(const string &duration);
    bool doSchedulesOverlap(Schedule schedule1, Schedule schedule2);

    bool hasScheduleConflict(Schedule &schedule1, Schedule &schedule2);
};

#endif // STUDENT_CLASSES_H