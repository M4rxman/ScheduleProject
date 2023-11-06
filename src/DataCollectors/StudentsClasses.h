//
// Created by alex2 on 29.10.2023.
//
/**
 * @file StudentsClasses.h
 * @brief Header file for the StudentsClasses class.
 */
#ifndef SCHEDULE_STUDENTSCLASSES_H
#define SCHEDULE_STUDENTSCLASSES_H
#include "../ClassesStruct/Student.h"
/**
 * @class StudentsClasses
 * @brief Represents a collection of students and their class assignments.
 */
class StudentsClasses {
    list<Student> student;

public:
    /**
     * @brief Read student data from an input file and populate the class.
     * @param f Input file stream to read student data from.
     */
    void readFile(ifstream& f);
    /**
    * @brief Print the student data.
    */
    void printData();
    /**
    * @brief Set a new student with the given information.
    * @param givenStudentCode The code of the new student.
    * @param givenStudentName The name of the new student.
    * @param givenUcCode The UcCode associated with the student.
    * @param givenClassCode The ClassCode associated with the student.
    */
    void setNewStudent(string givenStudentCode, string givenStudentName,
                                string givenUcCode, string givenClassCode);
    /**
     * @brief Get a list of students and their class assignments.
     * @return List of Student objects.
     */
    list<Student> getStudents();
    /**
     * @brief Find a student by their code.
     * @param basicString The code of the student to search for.
     * @return A pointer to the Student if found, nullptr otherwise.
     */

    Student *findStudentByCode(const string &basicString);
    /**
    * @brief Check if a student is assigned to a specific UcCode.
    * @param student The Student object to check.
    * @param ucCode The UcCode to compare with.
    * @return True if the student is assigned to the UcCode, false otherwise.
    */
    bool isStudentInUc(Student student, UcCode ucCode) const;
};


#endif //SCHEDULE_STUDENTSCLASSES_H
