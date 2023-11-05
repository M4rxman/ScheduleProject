//
// Created by alex2 on 29.10.2023.
//

#include <iostream>
#include "StudentsClasses.h"
#include <fstream>

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

list<Student> StudentsClasses::getStudents() {
    return this->student;
}
