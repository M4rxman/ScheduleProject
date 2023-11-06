//
// Created by Olek on 28.10.2023.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <iomanip>
#include "ClassesSchedule.h"
/**
 * @brief Read data from an input file and populate the class, using information from ClassesPerUc.
 * @param f Input file stream to read data from.
 * @param classesPerUc Reference to a ClassesPerUc object for additional information.
 */

void ClassesSchedule::readFile(ifstream &f, ClassesPerUc& classesPerUc) {
    string ucCode, stringClassCode, weekday, startHour, duration, type,
    skippingString;

    if (!f.is_open()) {
        cerr << "Error: File not open." << endl;
        return;
    }

    getline(f, skippingString);

    while (getline(f, stringClassCode, ',')) {
        getline(f, ucCode, ',');
        getline(f, weekday, ',');
        getline(f, startHour, ',');
        getline(f, duration, ',');
        getline(f, type);

        for (UcCode &ucCodeClass : classesPerUc.getClassesPerUc()) {
            for (ClassCode &classCode : ucCodeClass.getClassCodes()) {
                if (stringClassCode == classCode.getCode() &&
                    ucCode == ucCodeClass.getUcCode()) {
                    Schedule timeTable(weekday, startHour, duration, type, stringClassCode);
                    classCode.addSchedule(timeTable);
                }
            }
        }
    }

    f.close();
}
/**
 * @brief Print the data in the schedule, using information from ClassesPerUc.
 * @param classesPerUc Reference to a ClassesPerUc object for additional information.
 */
void ClassesSchedule::printData(ClassesPerUc& classesPerUc) {
    for (UcCode &ucCodeClass : classesPerUc.getClassesPerUc()) {
        std::cout << "UcCode: " << ucCodeClass.getUcCode() << std::endl;

        for (ClassCode &classCode : ucCodeClass.getClassCodes()) {
            std::cout << "ClassCode: " << classCode.getCode() << std::endl;

            // Determine the maximum length of each field for alignment
            size_t maxWeekdayLength = 0;
            size_t maxStartHourLength = 0;
            size_t maxDurationLength = 0;
            size_t maxTypeLength = 0;

            for (Schedule schedule : classCode.getSchedule()) {
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
            for (Schedule schedule : classCode.getSchedule()) {
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
        std::cout << "########" + ucCodeClass.getUcCode() + "########" <<  std::endl;
    }
}
/**
 * @brief Get a list of UcCode objects associated with ClassCodes in the schedule.
 * @return List of UcCode objects with associated ClassCodes.
 */
list<UcCode> ClassesSchedule::getUcClassCodes() {
    return this->ucCodeClassCode;
}
