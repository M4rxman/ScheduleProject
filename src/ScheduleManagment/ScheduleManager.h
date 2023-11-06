//
// Created by alex2 on 04.11.2023.
//
/**
 * @file ScheduleManager.h
 * @brief Declaration of the ScheduleManager class.
 */
#ifndef SCHEDULE_SCHEDULEMANAGER_H
#define SCHEDULE_SCHEDULEMANAGER_H


#include <iostream>
#include "StudentsClasses.h"
#include "ClassesSchedule.h"
/**
 * @class ScheduleManager
 * @brief Manages class schedules and student information.
 *
 * The ScheduleManager class provides methods for loading, printing, and consulting class schedules
 * and student data. It also allows various queries related to the scheduling of classes.
 */
class ScheduleManager {
public:
    /**
        * @brief Constructor for ScheduleManager class.
        * @param classesPerUcFile The file containing classes per UC data.
        * @param studentsClassesFile The file containing student classes data.
        * @param classesScheduleFile The file containing class schedules data.
        */
    ScheduleManager(const std::string& classesPerUcFile, const std::string& studentsClassesFile, const std::string& classesScheduleFile) {
     /**
     * @brief Print the classes per UC data.
     */
        loadClassesPerUcData(classesPerUcFile);
        loadStudentsClassesData(studentsClassesFile);
        loadClassesScheduleData(classesScheduleFile);
    }

    void printClassesPerUc() {
        classesPerUc.printData();
    }
     /**
     * @brief Print the students' classes data.
     */
    void printStudentsClasses() {
        studentsClasses.printData();
    }
    /**
     * @brief Print the class schedule data.
     */
    void printClassesSchedule() {
        classesSchedule.printData(classesPerUc);
    }
    /**
    * @brief Consult a student's schedule by student code.
    * @param studentCode The code of the student to consult.
    */
    void consultStudentSchedule(const std::string& studentCode);
    /**
     * @brief Consult a class schedule by class code.
     * @param classCode The code of the class to consult.
     */
    void consultClassSchedule(const std::string& classCode);
    /**
     * @brief Consult menu options for further queries.
     * @return The selected menu option.
     */
    int consultMenu();

private:
    StudentsClasses studentsClasses;
    ClassesSchedule classesSchedule;
    /**
     * @brief Load data from the classes per UC file.
     * @param filename The filename to load data from.
     */
    void loadClassesPerUcData(const std::string& filename);
    /**
     * @brief Load data from the classes schedule file.
     * @param filename The filename to load data from.
     */
    void loadClassesScheduleData(const std::string& filename);
    /**
     * @brief Load data from the students' classes file.
     * @param filename The filename to load data from.
     */
    void loadStudentsClassesData(const std::string& filename);
    /**
     * @brief Consult students in a class/course/year.
     * @param courseOrYear The course or year to query.
     */
    void consultStudentsInClassCourseYear(const string &courseOrYear);
    /**
    * @brief Consult students in at least N UCs.
    * @param n The minimum number of UCs for a student.
    */
    void consultStudentsInAtLeastNUCs(int n);
    /**
    * @brief Consult the UC with the most students.
    */
    void consultUcWithMostStudents();

protected:
    ClassesPerUc classesPerUc;
};


#endif //SCHEDULE_SCHEDULEMANAGER_H
