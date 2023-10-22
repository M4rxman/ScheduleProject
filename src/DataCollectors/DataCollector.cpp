#include <iostream>
#include <string>
#include <fstream>
#include "DataCollector.h"


/// https://www.youtube.com/watch?v=JpAiTSnnCdc&ab_channel=Unwithered

void ClassesPerUcCollector::AddElements(ClassesPerUc classesPerUc) {
    _classesPerUcData.insert(classesPerUc); // fix it later
}

void ClassesPerUcCollector::readFile(ifstream &f) {
    string ucCode, classCode;
    while(!f.eof()){
        getline(f, ucCode, ',');
        getline(f, classCode);
        ClassesPerUc info = ClassesPerUc(ucCode, classCode);
       AddElements(info);
    }
}
