//
// Created by alex2 on 04.11.2023.
//

#ifndef SCHEDULE_SCHEDULEMANAGER_H
#define SCHEDULE_SCHEDULEMANAGER_H


#include <iostream>
#include "StudentsClasses.h"
#include "ClassesSchedule.h"

class ScheduleManager {
public:
    ScheduleManager(const std::string& classesPerUcFile, const std::string& studentsClassesFile, const std::string& classesScheduleFile) {
        loadClassesPerUcData(classesPerUcFile);
        loadStudentsClassesData(studentsClassesFile);
        loadClassesScheduleData(classesScheduleFile);
    }

    void printClassesPerUc() {
        classesPerUc.printData();
    }

    void printStudentsClasses() {
        studentsClasses.printData();
    }

    void printClassesSchedule() {
        classesSchedule.printData(classesPerUc);
    }

    void consultStudentSchedule(const std::string& studentCode);
    void consultClassSchedule(const std::string& classCode);
    int consultMenu();

private:
    ClassesPerUc classesPerUc;
    StudentsClasses studentsClasses;
    ClassesSchedule classesSchedule;

    void loadClassesPerUcData(const std::string& filename);
    void loadClassesScheduleData(const std::string& filename);
    void loadStudentsClassesData(const std::string& filename);

    void consultStudentsInClassCourseYear(const string &courseOrYear);
    void consultStudentsInAtLeastNUCs(int n);
    void consultUcWithMostStudents();
};


#endif //SCHEDULE_SCHEDULEMANAGER_H
