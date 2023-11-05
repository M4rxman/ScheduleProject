#include "Student.h"

Student::Student() {
    // Default constructor initializes the object
}

Student::Student(string studentCode, string studentName, list<UcCode> ucCode) {
    setStudentCode(studentCode);
    setStudentName(studentName);
    setUcCode(ucCode);
}



void Student::setStudentCode(string studentCode) {
    this->studentCode = studentCode;
}

void Student::setStudentName(string studentName) {
    this->studentName = studentName;
}

void Student::setUcCode(list<UcCode> ucCode) {
    this->ucCode = ucCode;
}

string Student::getStudentCode() {
    return studentCode;
}

string Student::getStudentName() {
    return studentName;
}

list<UcCode> Student::getUcCodelist() {
    return this->ucCode;
}

bool Student::operator<(const Student& code) const {
    return this->studentCode < code.studentCode;
}

//non-standard shit

void Student::addUcCode(UcCode newUcCode) {
    this->ucCode.emplace_back(newUcCode);
}

list<ClassCode> Student::getClassCodeByUcCode(UcCode givenUcCode) {
    for(UcCode fUcCode : this->ucCode){
        if(givenUcCode.getUcCode() == fUcCode.getUcCode()){
            return fUcCode.getClassCodes();
        }
    }
    return list<ClassCode>();
}

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

vector<Schedule> Student::getSchedule() {
    vector<Schedule> result;
    for(UcCode& uc : ucCode){
        for(ClassCode classCode : uc.getClassCodes()){
            result.push_back(classCode.getSchedule());
        }
    }
    return result;
}





