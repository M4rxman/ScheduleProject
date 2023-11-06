/**
 * @file Student_Classes.h
 * @brief Header file defining the Student class and related data structures.
 */
#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include "UcCode.h"
#include <vector>

using namespace std;
/**
 * @class Student
 * @brief Represents a student with associated information.
 */
class Student {
    string studentCode;
    string studentName;
    list<UcCode> ucCode;

public:
    /**
     * @brief Default constructor for the Student class.
     */
    Student();
    /**
 * @brief Parameterized constructor for the Student class.
 * @param studentCode The student's code.
 * @param studentName The student's name.
 * @param ucCode A list of UcCode objects associated with the student.
 */

    Student(string studentCode, string studentName, list<UcCode> ucCode);
    /**
    * @brief Sets the student's code.
    * @param studentCode The student's code to set.
    */
    void setStudentCode(string studentCode);
    /**
     * @brief Sets the student's name.
     * @param studentName The student's name to set.
     */
    void setStudentName(string studentName);
    /**
     * @brief Sets the list of UcCode objects associated with the student.
     * @param ucCode The list of UcCode objects to set.
     */
    void setUcCode( list<UcCode> ucCode);
    /**
     * @brief Adds a new UcCode to the student's list.
     * @param newUcCode The UcCode to add.
     */
    void addUcCode(UcCode newUcCode);
    /**
     * @brief Gets the student's code.
     * @return The student's code.
     */
    string getStudentCode();
    /**
     * @brief Gets the student's name.
     * @return The student's name.
     */
    string getStudentName();
    /**
     * @brief Gets the list of UcCode objects associated with the student.
     * @return The list of UcCode objects.
     */
    list<UcCode> getUcCodelist();
    /**
    * @brief Retrieves a list of ClassCode objects associated with a given UcCode.
    * @param givenUcCode The UcCode to search for.
    * @return A list of ClassCode objects.
    */
    list<ClassCode> getClassCodeByUcCode(UcCode givenUcCode);
    /**
    * @brief Custom less than operator for sorting students by student code.
    * @param code The Student object to compare to.
    * @return True if this student's code is less than the other student's code, otherwise false.
    */
    vector<Schedule> getScheduleByClassCode(ClassCode givenClassCode);
    /**
     * @brief Retrieves a vector of Schedule objects for a given ClassCode.
     * @param givenClassCode The ClassCode to search for.
     * @return A vector of Schedule objects.
     */
    bool operator < (const Student& code) const;
    /**
    * @brief Retrieves a vector of Schedule objects for a given ClassCode.
    * @param givenClassCode The ClassCode to search for.
    * @return A vector of Schedule objects.
    */
    vector<Schedule> getSchedule();
    /**
    * @brief Removes a specific UcCode from the student's list.
    * @param code The UcCode to remove.
    */

    void removeUcCode(UcCode code);
    /**
     * @brief Convert time in the format "HH:MM" to minutes.
     * @param time The time in "HH:MM" format.
     * @return The time converted to minutes.
     */

    int timeToMinutes(const string &time);
    /**
     * @brief Convert duration in the format "HH:MM" to minutes.
     * @param duration The duration in "HH:MM" format.
     * @return The duration converted to minutes.
     */
    int durationToMinutes(const string &duration);
    /**
     * @brief Check if two schedules overlap.
     * @param schedule1 The first schedule to compare.
     * @param schedule2 The second schedule to compare.
     * @return True if the schedules overlap, false otherwise.
     */
    bool doSchedulesOverlap(Schedule schedule1, Schedule schedule2);
    /**
   * @brief Check if there is a schedule conflict between two schedules.
   * @param schedule1 The first schedule to compare.
   * @param schedule2 The second schedule to compare.
   * @return True if there is a schedule conflict, false otherwise.
   */
    bool hasScheduleConflict(Schedule &schedule1, Schedule &schedule2);
};

#endif // STUDENT_CLASSES_H