//
// Created by alex2 on 26.10.2023.
//
/**
 * @file UcCode.h
 * @brief Header file for the UcCode class.
 */
#include <string>
#include <list>
#include "ClassCode.h"
#ifndef SCHEDULE_UCCODE_H
#define SCHEDULE_UCCODE_H
/**
 * @class UcCode
 * @brief Represents a UcCode with associated ClassCodes.
 */
using namespace std;


class UcCode {
    string ucCode;
    list<ClassCode> classCode;

public:
/**
     * @brief Constructor for the UcCode class.
     * @param _ucCode The UcCode value.
     * @param classCode The list of associated ClassCodes.
     */
    UcCode(string _ucCode, list<ClassCode> classCode);
    /**
     * @brief Set the UcCode value.
     * @param ucCode The UcCode to set.
     */
    void SetUcCode(string ucCode);
    /**
     * @brief Get the UcCode value.
     * @return The UcCode value.
     */
    string getUcCode();
    /**
     * @brief Get a reference to the list of associated ClassCodes.
     * @return Reference to the list of associated ClassCodes.
     */
    list<ClassCode>& getClassCodes();
    /**
     * @brief Less-than comparison operator for UcCode objects.
     * @param code The UcCode to compare with.
     * @return True if this UcCode is less than the other UcCode, false otherwise.
     */
    bool operator<(const UcCode &code) const;
    /**
     * @brief Add a ClassCode to the list of associated ClassCodes.
     * @param leic The ClassCode to add.
     */
    void addClassCode(string leic);

};

#endif //SCHEDULE_UCCODE_H
