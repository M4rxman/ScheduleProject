#include "Student.h"

Student::Student() {
    // Default constructor initializes the object
}

Student::Student(string studentCode, string studentName, string ucCode, string classCode) {
    SetStudentCode(studentCode);
    SetStudentName(studentName);
    SetUcCode(ucCode);
    SetClassCode(classCode);
}

void Student::SetStudentCode(string studentCode) {
    _studentCode = studentCode;
}

void Student::SetStudentName(string studentName) {
    _studentName = studentName;
}

void Student::SetUcCode(string ucCode) {
    _ucCode = ucCode;
}

void Student::SetClassCode(string classCode) {
    _classCode = classCode;
}

string Student::GetStudentCode() {
    return _studentCode;
}

string Student::GetStudentName() {
    return _studentName;
}

string Student::GetUcCode() {
    return _ucCode;
}

string Student::GetClassCode() {
    return _classCode;
}

bool Student::operator<(const Student& code) const {
    return this->_studentCode < code._studentCode;
}






