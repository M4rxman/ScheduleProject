//
// Created by alex2 on 28.10.2023.
//
/**
 * @file ClassCode.h
 *
 * This file contains the declaration of the ClassCode class, which represents a code associated
 * with a class and its schedules.
 */
#ifndef SCHEDULE_CLASSCODE_H
#define SCHEDULE_CLASSCODE_H
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "Schedule.h"

using namespace std;
/**
 * @class ClassCode
 *
 * @brief A class representing a code associated with a class and its schedules.
 */

class ClassCode {

    string code;
    vector<Schedule> schedules; // work to be done


public:
    /**
     * @brief Default constructor for the ClassCode class.
     */
    ClassCode();
    /**
    * @brief Constructor to create a ClassCode object with a specified code.
    *
    * @param leic The code to assign to the ClassCode object.
    */
    ClassCode(string leic);
    /**
    * @brief Add a schedule to the ClassCode object.
    *
    * @param timeTable The Schedule object to add.
    */
    void addSchedule(Schedule timeTable);
    /**
    * @brief Get the code associated with the ClassCode object.
    *
    * @return The code of the ClassCode.
    */
    string getCode();
    /**
     * @brief Get the schedules associated with the ClassCode object.
     *
     * @return A vector of Schedule objects representing the schedules.
     */
    vector<Schedule> getSchedule();
    /**
     * @brief Overloaded less than operator to compare ClassCode objects based on their code.
     *
     * @param classCode The ClassCode object to compare with.
     * @return True if this ClassCode's code is less than the other ClassCode's code, false otherwise.
     */
    bool operator<(const ClassCode &classCode) const;

    bool operator==(const ClassCode &other) const {
        return this->code == other.code; // You might need to consider Schedule objects in your comparison
    }

    ClassCode(list <ClassCode> code);
};

#endif //SCHEDULE_CLASSCODE_H
