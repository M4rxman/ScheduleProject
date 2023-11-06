//
// Created by alex2 on 28.10.2023.
//
/**
 * @file Schedule.h
 *
 * This file contains the declaration of the Schedule class, which represents a schedule
 * for a class or event.
 */
#ifndef SCHEDULE_SCHEDULE_H
#define SCHEDULE_SCHEDULE_H
#include <string>
#include <vector>

using namespace std;
/**
 * @class Schedule
 *
 * @brief A class representing a schedule for a class or event.
 */

class Schedule {
    string weekday;
    string startHour;
    string duration;
    string type;
    string codeClass;

public:
    /**
     * @brief Default constructor for the Schedule class.
     */
    Schedule();
    /**
   * @brief Constructor to create a Schedule object with specific details.
   *
   * @param weekday The day of the week for the schedule.
   * @param startHour The start hour of the schedule.
   * @param duration The duration of the schedule.
   * @param type The type of schedule (e.g., lecture, lab, etc.).
   * @param codeClass The code associated with the class or event.
   */
    Schedule(string weekday, string startHour, string duration, string type,  string codeClass);
    /**
     * @brief Get the day of the week for the schedule.
     *
     * @return The day of the week.
     */
    string getWeekday();
    /**
     * @brief Get the start hour of the schedule.
     *
     * @return The start hour.
     */
    string getStartHour();
    /**
     * @brief Get the duration of the schedule.
     *
     * @return The duration of the schedule.
     */
    string getDuration();
    /**
     * @brief Get the type of schedule.
     *
     * @return The type of schedule (e.g., lecture, lab, etc.).
     */
    string getScheduleType();
    /**
     * @brief Get the code associated with the class or event.
     *
     * @return The code associated with the class or event.
     */
    string getCodeClass();
    /**
     * @brief Constructor to create a Schedule object from a vector of Schedules.
     *
     * @param vector1 A vector of Schedule objects to create a new Schedule from.
     */

    Schedule(const vector<Schedule>& vector1);
};



#endif //SCHEDULE_SCHEDULE_H
