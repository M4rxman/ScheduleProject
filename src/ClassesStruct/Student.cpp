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

void Student::removeUcCode(UcCode ucCode_singular) {
    // Use the erase-remove idiom to remove the specified UC code from the list
    ucCode.erase(std::remove_if(ucCode.begin(), ucCode.end(),[&ucCode_singular](UcCode& code){
        return code.getUcCode() == ucCode_singular.getUcCode();
    }), ucCode.end());
}

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

bool Student::doSchedulesOverlap(Schedule schedule1, Schedule schedule2) {
    int startTime1 = timeToMinutes(schedule1.getStartHour());
    int startTime2 = timeToMinutes(schedule2.getStartHour());
    int endTime1 = startTime1 + durationToMinutes(schedule1.getDuration());
    int endTime2 = startTime2 + durationToMinutes(schedule2.getDuration());

    return (endTime1 > startTime2) && (endTime2 > startTime1);
}




