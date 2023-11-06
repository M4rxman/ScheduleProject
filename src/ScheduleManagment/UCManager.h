//
// Created by alex2 on 05.11.2023.
//
/**
 * @file UCManager.h
 * @brief Declaration of the UCManager class.
 */
#ifndef SCHEDULE_UCMANAGER_H
#define SCHEDULE_UCMANAGER_H


#include "StudentsClasses.h"
#include "ScheduleManager.h"
/**
 * @class UCManager
 * @brief Manages student registrations in UCs (Courses).
 *
 * The UCManager class is responsible for managing student registrations in UCs (Courses). It provides
 * methods for adding, removing, and switching students between UCs, enforcing UC-specific rules.
 */
class UCManager : private ScheduleManager{

public:
    /**
    * @brief Constructor for UCManager class.
    * @param classesPerUcFile The file containing classes per UC data.
    * @param studentsClassesFile The file containing student classes data.
    * @param classesScheduleFile The file containing class schedules data.
    * @param classesPerUc Reference to the ClassesPerUc object.
    * @param studentsClasses Reference to the StudentsClasses object.
    * @param studentsClasses1 Reference to an additional StudentsClasses object.
    */
    UCManager(const string &classesPerUcFile, const string &studentsClassesFile, const string &classesScheduleFile,
              ClassesPerUc &classesPerUc, StudentsClasses &studentsClasses, ClassesSchedule &classesSchedule,
              StudentsClasses &studentsClasses1)
            : ScheduleManager(classesPerUcFile, studentsClassesFile, classesScheduleFile),
              studentsClasses(studentsClasses1) {}

    /**
     * @brief Add a student to a UC (Course).
     * @param studentCode The code of the student to be added.
     * @param ucCode The code of the UC (Course) to add the student to.
     * @return True if the addition was successful, false otherwise.
     */
    // Function to add a student to a UC
    bool addStudentToUC(const std::string& studentCode, const std::string& ucCode);
    /**
     * @brief Remove a student from a UC (Course).
     * @param studentCode The code of the student to be removed.
     * @param ucCode The code of the UC (Course) to remove the student from.
     * @return True if the removal was successful, false otherwise.
     */
    // Function to remove a student from a UC
    bool removeStudentFromUC(const std::string& studentCode, const std::string& ucCode);
    /**
     * @brief Switch a student from one UC to another.
     * @param studentCode The code of the student to be switched.
     * @param oldUCCode The code of the current UC.
     * @param newUCCode The code of the new UC.
     * @return True if the switch was successful, false otherwise.
     */
    // Function to switch a student from one UC to another
    bool switchStudentUC(const std::string& studentCode, const std::string& oldUCCode, const std::string& newUCCode);

private:
    StudentsClasses& studentsClasses;
/**
     * @brief Check if it's possible to add a student to a UC.
     * @param student The student object to add.
     * @param ucCode The UC code to add the student to.
     * @return True if the addition is allowed, false otherwise.
     */
    // Helper functions to enforce UC-specific rules
    bool canAddStudentToUC(Student& student, UcCode ucCode);
    /**
    * @brief Check if it's possible to remove a student from a UC.
    * @param student The student object to remove.
    * @param ucCode The UC code to remove the student from.
    * @return True if the removal is allowed, false otherwise.
    */
    bool canRemoveStudentFromUC(Student& student, UcCode& ucCode);
    /**
    * @brief Check if it's possible to switch a student from one UC to another.
    * @param student The student object to switch.
    * @param oldUCCode The code of the current UC.
    * @param newUCCode The code of the new UC.
    * @return True if the switch is allowed, false otherwise.
    */
    bool canSwitchStudentUC(Student& student, UcCode& oldUCCode, UcCode& newUCCode);
};



#endif //SCHEDULE_UCMANAGER_H
