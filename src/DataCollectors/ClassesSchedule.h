//
// Created by alex2 on 28.10.2023.
//

#ifndef SCHEDULE_CLASSESSCHEDULE_H
#define SCHEDULE_CLASSESSCHEDULE_H
#include "ClassesPerUc.h"

using namespace std;
/**
 * @class ClassesSchedule
 * @brief Represents a schedule of classes associated with UcCodes.
 */
class ClassesSchedule {
    list<UcCode> ucCodeClassCode;

public:
    /**
     * @brief Read data from an input file and populate the class, using information from ClassesPerUc.
     * @param f Input file stream to read data from.
     * @param classesPerUc Reference to a ClassesPerUc object for additional information.
     */
    void readFile(ifstream& f, ClassesPerUc& classesPerUc);
    /**
     * @brief Add a ClassCode to the associated UcCode in the schedule.
     * @param classCode The ClassCode to add.
     * @param ucCode The UcCode to associate with the ClassCode.
     */
    void addClassesToUc(string  classCode, string ucCode);
    /**
   * @brief Print the data in the schedule, using information from ClassesPerUc.
   * @param classesPerUc Reference to a ClassesPerUc object for additional information.
   */
    void printData(ClassesPerUc& classesPerUc);
    /**
     * @brief Get a list of UcCode objects associated with ClassCodes in the schedule.
     * @return List of UcCode objects with associated ClassCodes.
     */
    list<UcCode> getUcClassCodes();

};


#endif //SCHEDULE_CLASSESSCHEDULE_H
