//
// Created by alex2 on 29.10.2023.
//

#include <iostream>
#include "StudentsClasses.h"
#include <fstream>
/**
 * @brief Print the student data.
 */
void StudentsClasses::printData() {

    if(student.empty()){
        std::cout << "StudentClasses list is empty" << std::endl;
    }

    for (Student studnetF : student) {
        std::cout << "Student Number: " << studnetF.getStudentCode() <<
        " Student Name: " << studnetF.getStudentName()<< std::endl;

        for(UcCode uc : studnetF.getUcCodelist()){
            if(uc.getUcCode() == "UcCode"){
                continue;
            }

            std::cout << "UcCode: " << uc.getUcCode();

            std::list<ClassCode>& classCodes = uc.getClassCodes();
            std::cout << " Classes : ";
            for (ClassCode& code : classCodes) {
                std::cout << code.getCode() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }
}
/**
 * @brief Read student data from an input file and populate the class.
 * @param f Input file stream to read student data from.
 */
void StudentsClasses::readFile(ifstream &f) {
    string studentCode, studentName, ucCode, classCode, skippingString;

    if (!f.is_open()) {
        cerr << "Error: File not open." << endl;
        return;
    }

    getline(f, skippingString); // Skip the header line

    while (getline(f, studentCode, ',')) {
        getline(f, studentName, ',');
        getline(f, ucCode, ',');
        getline(f, classCode);

        // Check if the student with the given code already exists
        bool studentFound = false;
        for (Student& student : student) {
            if (student.getStudentCode() == studentCode) {
                studentFound = true;

                // Find the student's UC or create a new one if not found
                bool ucFound = false;
                for (UcCode& studentUc : student.getUcCodelist()) {
                    if (studentUc.getUcCode() == ucCode) {
                        ucFound = true;
                        // Add the ClassCode to the UC
                        studentUc.addClassCode(classCode);
                        break;
                    }
                }

                if (!ucFound) {
                    // If the UC is not found for the student, add it to the student
                    student.addUcCode(UcCode(ucCode, list<ClassCode>{ClassCode(classCode)}));
                }

                break;
            }
        }

        if (!studentFound) {
            // If the student doesn't exist, create a new student with the UC and Class code
            /*
            Student newStudent(studentCode, studentName, list<UcCode>{UcCode(ucCode, list<ClassCode>{ClassCode(classCode)})});
            student.push_back(newStudent);*/
            setNewStudent(studentCode, studentName, ucCode, classCode);

        }
    }

    f.close();
}
/**
 * @brief Set a new student with the given information.
 * @param givenStudentCode The code of the new student.
 * @param givenStudentName The name of the new student.
 * @param givenUcCode The UcCode associated with the student.
 * @param givenClassCode The ClassCode associated with the student.
 */

void StudentsClasses::setNewStudent(string givenStudentCode, string givenStudentName, string givenUcCode,
                                    string givenClassCode) {{
        ClassCode newClassCode(givenClassCode);
        list<ClassCode> newListClassCode;
        newListClassCode.emplace_back(newClassCode);

        UcCode studentUc(givenUcCode, newListClassCode);
        list<UcCode> studentListUc;
        studentListUc.emplace_back(studentUc);
        Student registeredStudent(givenStudentCode,givenStudentName,studentListUc);

        this->student.emplace_back(registeredStudent);
    }

}
/**
 * @brief Get a list of students and their class assignments.
 * @return List of Student objects.
 */
list<Student> StudentsClasses::getStudents() {
    return this->student;
}
/**
 * @brief Find a student by their code.
 * @param basicString The code of the student to search for.
 * @return A pointer to the Student if found, nullptr otherwise.
 */
Student *StudentsClasses::findStudentByCode(const string& studentCode) {
    for (Student& student_singular : student) {
        if (student_singular.getStudentCode() == studentCode) {
            return &student_singular; // Return a pointer to the found student
        }
    }
    return nullptr; // Return nullptr if the student is not found
}
/**
 * @brief Check if a student is assigned to a specific UcCode.
 * @param student The Student object to check.
 * @param ucCode The UcCode to compare with.
 * @return True if the student is assigned to the UcCode, false otherwise.
 */
bool StudentsClasses::isStudentInUc(Student student, UcCode ucCode) const {
    for (Student s : this->student) {
        // Find the student by their unique identifier (e.g., student code)
        if (s.getStudentCode() == student.getStudentCode()) {
            // Check if the student is registered in the given UC
            for (UcCode uc : s.getUcCodelist()) {
                if (uc.getUcCode() == ucCode.getUcCode()) {
                    return true; // Student is registered in the UC
                }
            }
        }
    }
    return false; // Student is not registered in the UC
}
