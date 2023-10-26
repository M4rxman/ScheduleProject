#ifndef SCHEDULE_DATACOLLECTOR_H
#define SCHEDULE_DATACOLLECTOR_H

#include <set>
#include <fstream>
#include "../ClassesStruct/ClassesPerUc.h"

using namespace std;

class DataCollector {
    virtual void readFile(ifstream& f) = 0;
};

class ClassesPerUcCollector : public DataCollector{

public:
    set<ClassesPerUc> _classesPerUcData;
    void AddElements(ClassesPerUc classesPerUc);
    void readFile(ifstream& f);
};

#endif //SCHEDULE_DATACOLLECTOR_H