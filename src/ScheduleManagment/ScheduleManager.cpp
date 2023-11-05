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
            for (ClassCode &classCode: classesPerUc.getUcCodebyCode(ucCodeClass).getClassCodes()) {
                std::cout << "ClassCode: " << classCode.getCode() << std::endl;
                vector<Schedule> scheduleOutput = classCode.getSchedule();

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
                std::cout << "------------------------" << std::endl;
            }
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

void ScheduleManager::consultStudentsInClassCourseYear(const std::string& courseOrYear) {
    std::cout << "Consulting students in class/course/year: " << courseOrYear << std::endl;

    bool found = false;

    for (Student& student : studentsClasses.getStudents()) {
        if (student.getStudentCode().find(courseOrYear) != std::string::npos) {
            std::cout << "Student Number: " << student.getStudentCode()
                      << " Student Name: " << student.getStudentName() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No students found for class/course/year: " << courseOrYear << std::endl;
    }
}

void ScheduleManager::consultStudentsInAtLeastNUCs(int n) {
    std::cout << "Consulting students registered in at least " << n << " UCs" << std::endl;

    int count = 0;
    for (Student& student : studentsClasses.getStudents()) {
        if (student.getUcCodelist().size() >= n) {
            count++;
            std::cout << "Student Number: " << student.getStudentCode()
                      << " Student Name: " << student.getStudentName() << std::endl;
        }
    }

    if (count == 0) {
        std::cout << "No students registered in at least " << n << " UCs" << std::endl;
    }
}

int ScheduleManager::consultMenu() {
    int consultingChoise;
    string stringCode;

    while (true) {
        std::cout << "1. Consult via student code\n";
        std::cout << "2. Consult class code\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> consultingChoise;

        switch (consultingChoise) {
            case 1:
                std::cout << "Enter student code: \n";
                std::cin >> stringCode;
                consultStudentSchedule(stringCode);
                break;
            case 2:
                std::cout << "Enter class code: \n";
                std::cin >> stringCode;
                consultClassSchedule(stringCode);
                break;
            case 3:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }
    }
}
