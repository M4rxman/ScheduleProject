//
// Created by alex2 on 29.10.2023.
//

#ifndef SCHEDULE_STUDENTSCLASSES_H
#define SCHEDULE_STUDENTSCLASSES_H
#include "../ClassesStruct/Student.h"

class StudentsClasses {
    list<Student> student;

public:
    void readFile(ifstream& f);
    void printData();
    void setNewStudent(string givenStudentCode, string givenStudentName,
                                string givenUcCode, string givenClassCode);
    list<Student> getStudents();

};


#endif //SCHEDULE_STUDENTSCLASSES_H
