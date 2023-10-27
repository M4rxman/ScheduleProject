#ifndef SCHEDULE_DATACOLLECTOR_H
#define SCHEDULE_DATACOLLECTOR_H

#include <set>
#include <fstream>
#include "ClassesPerUc.h"

using namespace std;

class DataCollector {
    virtual void readFile(ifstream& f) = 0;
};
#endif //SCHEDULE_DATACOLLECTOR_H