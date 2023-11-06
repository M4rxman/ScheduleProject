#include <iostream>
#include "ScheduleManagment/ScheduleManager.h"

int main() {
    std::cout << "Schedule Management System" << std::endl;

    // Specify the file paths for classesPerUc, studentsClasses, and classesSchedule
    std::string classesPerUcFile = "C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes_per_uc.csv";
    std::string studentsClassesFile = "C:\\Users\\alex2\\Downloads\\schedule\\Data\\students_classes.csv";
    std::string classesScheduleFile = "C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes.csv";

    // Create a ScheduleManager instance
    ScheduleManager scheduleManager(classesPerUcFile, studentsClassesFile, classesScheduleFile);

    int menuChoice;
    string studentCode,classCode;

    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. View Classes Per Uc\n";
        std::cout << "2. View Students Classes\n";
        std::cout << "3. View Classes Schedule\n";
        std::cout << "4. Consult\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                std::cout << "Classes Per Uc" << std::endl;
                scheduleManager.printClassesPerUc();
                break;
            case 2:
                std::cout << "Students Classes" << std::endl;
                scheduleManager.printStudentsClasses();
                break;
            case 3:
                std::cout << "Classes Schedule" << std::endl;
                scheduleManager.printClassesSchedule();
                break;
            case 4:
                std::cout << "Consulting menu: " << std::endl;
                scheduleManager.consultMenu();
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }
    }

    return 0;
}