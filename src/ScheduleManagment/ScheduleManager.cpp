//
// Created by alex2 on 04.11.2023.
//

#include <iomanip>
#include <map>
#include "ScheduleManager.h"
#include "UCManager.h"

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
        for(UcCode studentUcCode : studentOutput.getUcCodelist()){
            for(ClassCode classCode : studentUcCode.getClassCodes()){
                if(!classesPerUc.getVerifyClassCode(classCode).getCode().empty()){
                    ClassCode verifyiedClassCode = classesPerUc.getVerifyClassCode(classCode);
                    std::cout << "UcCode: " << studentUcCode.getUcCode() << "\t";
                    std::cout << "ClassCode: " << verifyiedClassCode.getCode() << std::endl;
                    vector<Schedule> scheduleOutput = verifyiedClassCode.getSchedule();

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
    std::cout << "------------------------" << std::endl;
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
    std::cout << "------------------------" << std::endl;
}

void ScheduleManager::consultUcWithMostStudents() {
    std::cout << "Consulting UCs with the greatest number of students" << std::endl;

    std::map<std::string, int> ucStudentCount;  // Map to store UCs and their student counts

    // Count the number of students in each UC
    for (Student& student : studentsClasses.getStudents()) {
        for (UcCode& ucCode : student.getUcCodelist()) {
            ucStudentCount[ucCode.getUcCode()]++;
        }
    }

    // Find the UC(s) with the greatest number of students
    int maxStudentCount = 0;
    std::vector<std::string> ucsWithMostStudents;

    for (const auto& pair : ucStudentCount) {
        if (pair.second > maxStudentCount) {
            maxStudentCount = pair.second;
            ucsWithMostStudents = {pair.first};
        } else if (pair.second == maxStudentCount) {
            ucsWithMostStudents.push_back(pair.first);
        }
    }

    // Display the UC(s) with the greatest number of students
    if (ucsWithMostStudents.empty()) {
        std::cout << "No UCs found." << std::endl;
    } else {
        std::cout << "UC(s) with the greatest number of students (" << maxStudentCount << " students):" << std::endl;
        for (const std::string& ucCode : ucsWithMostStudents) {
            std::cout << "UC Code: " << ucCode << std::endl;
        }
    }
    std::cout << "------------------------" << std::endl;
}

int ScheduleManager::consultMenu() {
    int consultingChoice, n;
    std::string stringCode, ucCode, oldUCCode, newUCCode;

    UCManager ucManager("classesPerUcFile", "studentsClassesFile", "classesScheduleFile", classesPerUc, studentsClasses, classesSchedule, studentsClasses);

    while (true) {
        std::cout << "1. Consult via student code\n";
        std::cout << "2. Consult class code\n";
        std::cout << "3. Consult the students within a given class, course or year\n";
        std::cout << "4. Consult the number of students registered in at least n UCs\n";
        std::cout << "5. Add student to a UC\n";
        std::cout << "6. Remove student from a UC\n";
        std::cout << "7. Switch student's UC\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> consultingChoice;

        switch (consultingChoice) {
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
                std::cout << "Enter class, course, or year: " << std::endl;
                std::cin >> stringCode;
                consultStudentsInClassCourseYear(stringCode);
                break;
            case 4:
                std::cout << "Enter the number of UCs: " << std::endl;
                std::cin >> n;
                consultStudentsInAtLeastNUCs(n);
                break;
            case 5:
                std::cout << "Enter student code: ";
                std::cin >> stringCode;
                std::cout << "Enter UC code: ";
                ucManager.addStudentToUC(stringCode, ucCode);
                break;
            case 6:
                std::cout << "Enter student code: ";
                std::cin >> stringCode;
                std::cout << "Enter UC code: ";
                std::cin >> ucCode;
                ucManager.removeStudentFromUC(stringCode, ucCode);
                break;
            case 7:
                std::cout << "Enter student code: ";
                std::cin >> stringCode;
                std::cout << "Enter old UC code: ";
                std::cin >> oldUCCode;
                std::cout << "Enter new UC code: ";
                std::cin >> newUCCode;
                ucManager.switchStudentUC(stringCode, oldUCCode, newUCCode);
                break;
            case 8:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }
    }
}

