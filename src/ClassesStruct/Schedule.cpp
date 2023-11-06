//
// Created by alex2 on 28.10.2023.
//
/**
 * @file Schedule.cpp
 *
 * This file contains the implementation of the Schedule class methods.
 */

#include <iostream>
#include "Schedule.h"
/**
 * @brief Default constructor for the Schedule class.
 */
Schedule::Schedule() {
}
/**
 * @brief Constructor to create a Schedule object with specific details.
 *
 * @param weekday The day of the week for the schedule.
 * @param startHour The start hour of the schedule.
 * @param duration The duration of the schedule.
 * @param type The type of schedule (e.g., lecture, lab, etc.).
 * @param codeClass The code associated with the class or event.
 */

Schedule::Schedule(string weekday, string startHour, string duration, string type,  string codeClass) {
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
    this->codeClass = codeClass;
}
/**
 * @brief Get the day of the week for the schedule.
 *
 * @return The day of the week.
 */
string Schedule::getWeekday() {
    return this->weekday;
}
/**
 * @brief Get the start hour of the schedule.
 *
 * @return The start hour.
 */
string Schedule::getStartHour() {
    return this->startHour;
}
/**
 * @brief Get the duration of the schedule.
 *
 * @return The duration of the schedule.
 */
string Schedule::getDuration() {
    return this->duration;
}
/**
 * @brief Get the type of schedule.
 *
 * @return The type of schedule (e.g., lecture, lab, etc.).
 */
string Schedule::getScheduleType() {
    return this->type;
}
/**
 * @brief Get the code associated with the class or event.
 *
 * @return The code associated with the class or event.
 */
string Schedule::getCodeClass() {
    return this->codeClass;
}
/**
 * @brief Constructor to create a Schedule object from a vector of Schedules.
 *
 * @param vector1 A vector of Schedule objects to create a new Schedule from.
 */
Schedule::Schedule(const vector<Schedule>& timeTable) {

}
