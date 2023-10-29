//
// Created by Olek on 28.10.2023.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "ClassesSchedule.h"


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
