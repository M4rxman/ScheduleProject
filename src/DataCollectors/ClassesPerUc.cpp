//
// Created by alex2 on 21.10.2023.
//

#include "ClassesPerUc.h"

// needs to be reworked may be

void ClassesPerUc::readFile(ifstream &f) {
    string ucCode,crutch_line, stringClassCode;
    list<string> classCode;
    getline(f, crutch_line); // an amazing crutch
    while(!f.eof()){
        getline(f, ucCode, ',');
        getline(f, stringClassCode);

        classCode.push_back(stringClassCode);
        crutch_line = ucCode;

        cPerUc.push_back(UcCode(ucCode, classCode));

        while(crutch_line == ucCode){
            getline(f, crutch_line, ',');
            getline(f, stringClassCode);
            classCode.push_back(stringClassCode);
        }
        cPerUc.push_back(UcCode(ucCode, classCode));

    }
}