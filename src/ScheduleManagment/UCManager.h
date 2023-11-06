//
// Created by alex2 on 05.11.2023.
//

#ifndef SCHEDULE_UCMANAGER_H
#define SCHEDULE_UCMANAGER_H


#include "StudentsClasses.h"
#include "ScheduleManager.h"

class UCManager : private ScheduleManager{

public:
    UCManager(const string &classesPerUcFile, const string &studentsClassesFile, const string &classesScheduleFile,
              ClassesPerUc &classesPerUc, StudentsClasses &studentsClasses, ClassesSchedule &classesSchedule,
              StudentsClasses &studentsClasses1)
            : ScheduleManager(classesPerUcFile, studentsClassesFile, classesScheduleFile),
              studentsClasses(studentsClasses1) {}


    // Function to add a student to a UC
    bool addStudentToUC(const std::string& studentCode, const std::string& ucCode);

    // Function to remove a student from a UC
    bool removeStudentFromUC(const std::string& studentCode, const std::string& ucCode);

    // Function to switch a student from one UC to another
    bool switchStudentUC(const std::string& studentCode, const std::string& oldUCCode, const std::string& newUCCode);

private:
    StudentsClasses& studentsClasses;

    // Helper functions to enforce UC-specific rules
    bool canAddStudentToUC(Student& student, UcCode ucCode);
    bool canRemoveStudentFromUC(Student& student, UcCode& ucCode);
    bool canSwitchStudentUC(Student& student, UcCode& oldUCCode, UcCode& newUCCode);
};



#endif //SCHEDULE_UCMANAGER_H
