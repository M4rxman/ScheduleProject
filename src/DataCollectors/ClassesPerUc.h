//
// Created by alex2 on 21.10.2023.
//
/**
 * @file ClassesPerUc.h
 * @brief Header file for the ClassesPerUc class.
 */
#include <list>
#include <string>
#include <fstream>
#include "../ClassesStruct/UcCode.h"

#ifndef SCHEDULE_CLASSESPERUCCOLLECTOR_H
/**
 * @class ClassesPerUc
 * @brief Represents a collection of UcCodes and their associated data.
 */
using namespace std;

class ClassesPerUc {
    list<UcCode> cPerUc; //ClassesPerUc list

public:
    /**
     * @brief Read data from an input file and populate the class.
     * @param f Input file stream to read data from.
     */
    void readFile(ifstream& f);
    /**
     * @brief Add a ClassCode to the associated UcCode in the collection.
     * @param classCode The ClassCode to add.
     * @param ucCode The UcCode to associate with the ClassCode.
     */
    void addClassesToUc(string  classCode, string ucCode);
    /**
     * @brief Print the data in the collection.
     */
    void printData();
    /**
     * @brief Get a UcCode object by its code.
     * @param ucCode The code of the UcCode to retrieve.
     * @return The UcCode object with the specified code.
     */
    UcCode getUcCodebyCode(UcCode ucCode);
    /**
     * @brief Get a reference to the list of UcCodes in the collection.
     * @return Reference to the list of UcCodes.
     */
    list<UcCode>& getClassesPerUc();
    /**
     * @brief Verify and get a ClassCode from the unverified ClassCode object.
     * @param unVerifiedClassCode The unverified ClassCode to verify.
     * @return The verified ClassCode.
     */
    ClassCode getVerifyClassCode(ClassCode unVerifiedClassCode);
    /**
    * @brief Find a UcCode by its code.
    * @param basicString The code of the UcCode to search for.
    * @return A pointer to the UcCode if found, nullptr otherwise.
    */
    UcCode *findUcCodeByCode(const string &basicString);
};

#endif //SCHEDULE_CLASSESPERUCCOLLECTOR_H
