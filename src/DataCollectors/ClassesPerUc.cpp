//
// Created by alex2 on 21.10.2023.
//

#include "ClassesPerUc.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

// needs to be reworked may be

void ClassesPerUc::readFile(ifstream &f) {
    string ucCode, stringClassCode;

    if (!f.is_open()) {
        cerr << "Error: File not open." << endl;
        return;
    }

    // Temporary map to store class codes for each unique ucCode
    map<string, list<string>> tempMap;

    while (getline(f, ucCode, ',')) {
        getline(f, stringClassCode);
        tempMap[ucCode].push_back(stringClassCode);
    }

    // Iterate through the map and use addClassesToUc function
    for (const auto &entry : tempMap) {
        const string &ucCode = entry.first;
        const list<string> &classCodes = entry.second;

        for (const string &classCode : classCodes) {
            addClassesToUc(classCode, ucCode);
        }
    }
}

void ClassesPerUc::addClassesToUc(string classCode, string ucCode) {
    // Iterate through the list of UcCode objects
    for (auto it = cPerUc.begin(); it != cPerUc.end(); ++it) {
        // Check if the ucCode of the current UcCode object matches the provided ucCode
        if (it->GetUcCode() == ucCode) {
            // If it matches, add the classCode to the UcCode object
            it->addClassCode(classCode);
            return; // Exit the loop once class code is added
        }
    }

    // If no matching UcCode object is found, create a new one
    cPerUc.push_back(UcCode(ucCode, {classCode}));
}

void ClassesPerUc::writeFile() {
    if(cPerUc.empty()){
        std::cout << "ClassesPerUc list is empty" << std::endl;
    }

    for (UcCode uc : cPerUc) {
        if(uc.ucCode == "UcCode"){
            continue;
        }

        std::cout << "UcCode: " << uc.GetUcCode() << std::endl;

        const std::list<std::string>& classCodes = uc.classCode;
        std::cout << "Class Codes: ";
        for (const std::string& code : classCodes) {
            std::cout << code << " ";
        }
        std::cout << std::endl;

        std::cout << "-----------------------------------" << std::endl;
    }
}