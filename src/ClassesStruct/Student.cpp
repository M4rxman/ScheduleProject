/**
 * @file Student.cpp
 *
 * This file contains the implementation of the Student class methods.
 */

#include "Student.h"
/**
 * @brief Default constructor for the Student class.
 */
Student::Student() {
    // Default constructor initializes the object
}

/**
 * @brief Parameterized constructor for the Student class.
 *
 * @param studentCode The student's code.
 * @param studentName The student's name.
 * @param ucCode A list of UcCode objects associated with the student.
 */
Student::Student(string studentCode, string studentName, list<UcCode> ucCode) {
    setStudentCode(studentCode);
    setStudentName(studentName);
    setUcCode(ucCode);
}
/**
 * @brief Sets the student's code.
 *
 * @param studentCode The student's code to set.
 */


void Student::setStudentCode(string studentCode) {
    this->studentCode = studentCode;
}
/**
 * @brief Sets the student's name.
 *
 * @param studentName The student's name to set.
 */
void Student::setStudentName(string studentName) {
    this->studentName = studentName;
}
/**
 * @brief Sets the list of UcCode objects associated with the student.
 *
 * @param ucCode The list of UcCode objects to set.
 */
void Student::setUcCode(list<UcCode> ucCode) {
    this->ucCode = ucCode;
}
/**
 * @brief Gets the student's code.
 *
 * @return The student's code.
 */
string Student::getStudentCode() {
    return studentCode;
}
/**
 * @brief Gets the student's name.
 *
 * @return The student's name.
 */
string Student::getStudentName() {
    return studentName;
}
/**
 * @brief Gets the list of UcCode objects associated with the student.
 *
 * @return The list of UcCode objects.
 */
list<UcCode> Student::getUcCodelist() {
    return this->ucCode;
}
/**
 * @brief Custom less than operator for sorting students by student code.
 *
 * @param code The Student object to compare to.
 *
 * @return True if this student's code is less than the other student's code, otherwise false.
 */
bool Student::operator<(const Student& code) const {
    return this->studentCode < code.studentCode;
}

//non-standard shit
/**
 * @brief Adds a new UcCode to the student's list.
 *
 * @param newUcCode The UcCode to add.
 */
void Student::addUcCode(UcCode newUcCode) {
    this->ucCode.emplace_back(newUcCode);
}
/**
 * @brief Retrieves a list of ClassCode objects associated with a given UcCode.
 *
 * @param givenUcCode The UcCode to search for.
 *
 * @return A list of ClassCode objects.
 */
list<ClassCode> Student::getClassCodeByUcCode(UcCode givenUcCode) {
    for(UcCode fUcCode : this->ucCode){
        if(givenUcCode.getUcCode() == fUcCode.getUcCode()){
            return fUcCode.getClassCodes();
        }
    }
    return list<ClassCode>();
}
/**
 * @brief Retrieves a vector of Schedule objects for a given ClassCode.
 *
 * @param givenClassCode The ClassCode to search for.
 *
 * @return A vector of Schedule objects.
 */
vector<Schedule> Student::getScheduleByClassCode(ClassCode givenClassCode) {
    for(UcCode fUcCode : this->ucCode){
        for(ClassCode searchedClassCode : fUcCode.getClassCodes()){
            if(givenClassCode.getCode() == searchedClassCode.getCode()){
                return searchedClassCode.getSchedule();
            }
        }
    }

    return vector<Schedule>();
}
/**
 * @brief Retrieves a vector of Schedule objects.
 *
 * @return A vector of Schedule objects.
 */
vector<Schedule> Student::getSchedule() {
    vector<Schedule> result;
    for(UcCode& uc : ucCode){
        for(ClassCode classCode : uc.getClassCodes()){
            result.push_back(classCode.getSchedule());
        }
    }
    return result;
}
/**
 * @brief Removes a specific UcCode from the student's list.
 *
 * @param ucCode_singular The UcCode to remove.
 */
void Student::removeUcCode(UcCode ucCode_singular) {
    // Use the erase-remove idiom to remove the specified UC code from the list
    ucCode.erase(std::remove_if(ucCode.begin(), ucCode.end(),[&ucCode_singular](UcCode& code){
        return code.getUcCode() == ucCode_singular.getUcCode();
    }), ucCode.end());
}
/**
 * @brief Convert time in the format "HH:MM" to minutes.
 *
 * @param time The time in "HH:MM" format.
 *
 * @return The time converted to minutes.
 */
bool Student::hasScheduleConflict(Schedule& schedule1, Schedule& schedule2) {
    int startTime1 = timeToMinutes(schedule1.getStartHour());
    int endTime1 = startTime1 + durationToMinutes(schedule1.getDuration());

    int startTime2 = timeToMinutes(schedule2.getStartHour());
    int endTime2 = startTime2 + durationToMinutes(schedule2.getDuration());

    // Check for conflicts
    if ((startTime1 >= startTime2 && startTime1 < endTime2) || (endTime1 > startTime2 && endTime1 <= endTime2) ||
        (startTime2 >= startTime1 && startTime2 < endTime1) || (endTime2 > startTime1 && endTime2 <= endTime1)) {
        return true; // There is a schedule conflict
    }

    return false; // No schedule conflict
}
/**
 * @brief Check if there is a schedule conflict between two schedules.
 *
 * @param schedule1 The first schedule to compare.
 * @param schedule2 The second schedule to compare.
 *
 * @return True if there is a schedule conflict, false otherwise.
 */
int Student::timeToMinutes(const std::string& time) {
    int hours, minutes;
    if (sscanf(time.c_str(), "%d:%d", &hours, &minutes) == 2) {
        return hours * 60 + minutes;
    }
    return 0; // Return 0 in case of invalid time format
}

int Student::durationToMinutes(const std::string& duration) {
    int hours, minutes;
    if (sscanf(duration.c_str(), "%d:%d", &hours, &minutes) == 2) {
        return hours * 60 + minutes;
    }
    return 0; // Return 0 in case of invalid duration format
}
/**
 * @brief Convert duration in the format "HH:MM" to minutes.
 *
 * @param duration The duration in "HH:MM" format.
 *
 * @return The duration converted to minutes.
 */
bool Student::doSchedulesOverlap(Schedule schedule1, Schedule schedule2) {
    int startTime1 = timeToMinutes(schedule1.getStartHour());
    int startTime2 = timeToMinutes(schedule2.getStartHour());
    int endTime1 = startTime1 + durationToMinutes(schedule1.getDuration());
    int endTime2 = startTime2 + durationToMinutes(schedule2.getDuration());

    return (endTime1 > startTime2) && (endTime2 > startTime1);
}




