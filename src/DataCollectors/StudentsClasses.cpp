//
// Created by alex2 on 29.10.2023.
//

#include <iostream>
#include "StudentsClasses.h"

void StudentsClasses::printData() {

    if(student.empty()){
        std::cout << "ClassesPerUc list is empty" << std::endl;
    }

    for (Student studnetF : student) {
        std::cout << "Student Number: " << studnetF.getStudentCode() <<
        " Student Name: " << studnetF.getStudentName()<< std::endl;

        for(UcCode uc : studnetF.getUcCodelist()){
            if(uc.getUcCode() == "UcCode"){
                continue;
            }

            std::cout << "UcCode: " << uc.getUcCode() << std::endl;

            std::list<ClassCode>& classCodes = uc.getClassCodes();
            std::cout << "Classes : ";
            for (ClassCode& code : classCodes) {
                std::cout << code.getCode() << " ";
                for (Schedule schedule : code.getSchedule()) {
                    std::cout << schedule.getWeekday() << " " << schedule.getStartHour() << endl;
                    std::cout << schedule.getDuration() << " " << schedule.getScheduleType() << endl;
                }
            }
            std::cout << std::endl;

            std::cout << "-----------------------------------" << std::endl;
        }
        }


}
