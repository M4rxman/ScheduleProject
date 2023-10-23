#include <iostream>
#include <string>
#include <fstream>
#include "DataCollector.h"


/// https://www.youtube.com/watch?v=JpAiTSnnCdc&ab_channel=Unwithered



void ClassesPerUcCollector::AddElements(ClassesPerUc classesPerUc) {
    _classesPerUcData.insert(classesPerUc);
}

void ClassesPerUcCollector::readFile(ifstream &f) {
    string ucCode, classCode, first_line;
    getline(f, first_line); // an amazing crutch
    while(!f.eof()){

        getline(f, ucCode, ',');
        getline(f, classCode);
        ClassesPerUc info = ClassesPerUc(ucCode, classCode);
       AddElements(info);
    }
}

/////////////////////


