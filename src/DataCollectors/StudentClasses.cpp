#include "StudentClasses.h"

StudentClasses::StudentClasses() {
    // Default constructor initializes the object
}

StudentClasses::StudentClasses(string studentCode, string studentName, string ucCode, string classCode) {
    SetStudentCode(studentCode);
    SetStudentName(studentName);
    SetUcCode(ucCode);
    SetClassCode(classCode);
}

void StudentClasses::SetStudentCode(string studentCode) {
    _studentCode = studentCode;
}

void StudentClasses::SetStudentName(string studentName) {
    _studentName = studentName;
}

void StudentClasses::SetUcCode(string ucCode) {
    _ucCode = ucCode;
}

void StudentClasses::SetClassCode(string classCode) {
    _classCode = classCode;
}

string StudentClasses::GetStudentCode() {
    return _studentCode;
}

string StudentClasses::GetStudentName() {
    return _studentName;
}

string StudentClasses::GetUcCode() {
    return _ucCode;
}

string StudentClasses::GetClassCode() {
    return _classCode;
}

bool StudentClasses::operator<(const StudentClasses& code) const {
    return this->_studentCode < code._studentCode;
}






