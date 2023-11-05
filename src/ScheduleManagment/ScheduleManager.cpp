//
// Created by alex2 on 04.11.2023.
//

#include <iomanip>
#include "ScheduleManager.h"

void ScheduleManager::loadClassesPerUcData(const string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        classesPerUc.readFile(file);
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

void ScheduleManager::loadStudentsClassesData(const string &filename){
    std::ifstream file(filename);
    if (file.is_open()) {
        studentsClasses.readFile(file);
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

void ScheduleManager::loadClassesScheduleData(const string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        classesSchedule.readFile(file, classesPerUc);
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

// Function to consult the schedule of a given student or class
void ScheduleManager::consultStudentSchedule(const std::string& studentCode) {
    std::cout << "Consulting schedule for Student: " << studentCode << std::endl;
    Student studentOutput;
    bool found = false;

    for (Student &student: studentsClasses.getStudents()) {
        if (student.getStudentCode() == studentCode) {
            found = true;
            studentOutput = student;
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found." << std::endl;
    } else {
        for (UcCode &ucCodeClass: studentOutput.getUcCodelist()) {
            std::cout << "UcCode: " << ucCodeClass.getUcCode() << std::endl;
            for (ClassCode &classCode: ucCodeClass.getClassCodes()) {
                std::cout << "ClassCode: " << classCode.getCode() << std::endl;
                // Determine the maximum length of each field for alignment
                size_t maxWeekdayLength = 0;
                size_t maxStartHourLength = 0;
                size_t maxDurationLength = 0;
                size_t maxTypeLength = 0;

                for (Schedule schedule: classCode.getSchedule()) {
                    if (schedule.getWeekday().length() > maxWeekdayLength) {
                        maxWeekdayLength = schedule.getWeekday().length();
                    }
                    if (schedule.getStartHour().length() > maxStartHourLength) {
                        maxStartHourLength = schedule.getStartHour().length();
                    }
                    if (schedule.getDuration().length() > maxDurationLength) {
                        maxDurationLength = schedule.getDuration().length();
                    }
                    if (schedule.getScheduleType().length() > maxTypeLength) {
                        maxTypeLength = schedule.getScheduleType().length();
                    }
                }

                // Print the schedules in aligned columns
                for (Schedule schedule: classCode.getSchedule()) {
                    std::cout << "Weekday: " << std::left << std::setw(maxWeekdayLength) << schedule.getWeekday();
                    std::cout << "   ";
                    std::cout << "StartHour: " << std::left << std::setw(maxStartHourLength) << schedule.getStartHour();
                    std::cout << "   ";
                    std::cout << "Duration: " << std::left << std::setw(maxDurationLength) << schedule.getDuration();
                    std::cout << "   ";
                    std::cout << "Type: " << std::left << std::setw(maxTypeLength) << schedule.getScheduleType();
                    std::cout << std::endl;
                }
                std::cout << "------------------------" << std::endl;
            }
            std::cout << "########" + ucCodeClass.getUcCode() + "########" << std::endl;
        }
    }
}

// Consult the schedule of a given class
void ScheduleManager::consultClassSchedule(const std::string& classCode) {
    std::cout << "Consulting schedule for Class: " << classCode << std::endl;

    bool found = false;

    for (UcCode& ucCode : classesPerUc.getClassesPerUc()) {
        for (ClassCode& givenClassCode : ucCode.getClassCodes()) {
            if (givenClassCode.getCode() == classCode) {
                std::cout << "------------------------" << std::endl;
                std::cout << "UcCode :" << ucCode.getUcCode() << std::endl;
                std::cout << "------------------------" << std::endl;
                vector<Schedule> scheduleOutput = givenClassCode.getSchedule();
                for(auto it = scheduleOutput.begin(); it != scheduleOutput.end(); it++){
                    std::cout << "Weekday: " << std::left << std::setw(it->getWeekday().length()) << it->getWeekday();
                    std::cout << "   ";
                    std::cout << "StartHour: " << std::left << std::setw(it->getStartHour().length()) << it->getStartHour();
                    std::cout << "   ";
                    std::cout << "Duration: " << std::left << std::setw(it->getDuration().length()) << it->getDuration();
                    std::cout << "   ";
                    std::cout << "Type: " << std::left << std::setw(it->getScheduleType().length()) << it->getScheduleType();
                    std::cout << std::endl;
                }
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Class not found." << std::endl;
    }
}