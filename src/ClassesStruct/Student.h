#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include "UcCode.h"
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
};

#endif // STUDENT_CLASSES_H