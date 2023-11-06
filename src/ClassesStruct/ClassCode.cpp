//
// Created by alex2 on 28.10.2023.
//
#include "Schedule.h"
#include "ClassCode.h"
/**
 * @brief Default constructor for the ClassCode class.
 */
ClassCode::ClassCode() {}
/**
 * @brief Constructor to create a ClassCode object with a specified code.
 *
 * @param leic The code to assign to the ClassCode object.
 */
ClassCode::ClassCode(string leic) {
    this->code = leic;
}
/**
 * @brief Overloaded less than operator to compare ClassCode objects based on their code.
 *
 * @param classCode The ClassCode object to compare with.
 * @return True if this ClassCode's code is less than the other ClassCode's code, false otherwise.
 */
bool ClassCode::operator<(const ClassCode &classCode) const {
    return this->code < classCode.code;
}
/**
 * @brief Add a schedule to the ClassCode object.
 *
 * @param timeTable The Schedule object to add.
 */
void ClassCode::addSchedule(Schedule timeTable) {
    this->schedules.emplace_back(timeTable);
}
/**
 * @brief Get the code associated with the ClassCode object.
 *
 * @return The code of the ClassCode.
 */
string ClassCode::getCode() {
    return this->code;
}

/**
 * @brief Get the schedules associated with the ClassCode object.
 *
 * @return A vector of Schedule objects representing the schedules.
 */
vector<Schedule> ClassCode::getSchedule() {
    return this->schedules;
}


