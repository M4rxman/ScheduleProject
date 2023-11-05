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
    string ucCode, stringClassCode, skippingString;

    if (!f.is_open()) {
        cerr << "Error: File not open." << endl;
        return;
    }

    getline(f, skippingString);

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

    f.close();
}

void ClassesPerUc::addClassesToUc(string classCode, string ucCode) {
    // Iterate through the list of UcCode objects
    for (auto it = cPerUc.begin(); it != cPerUc.end(); ++it) {
        // Check if the ucCode of the current UcCode object matches the provided ucCode
        if (it->getUcCode() == ucCode) {
            // If it matches, add the classCode to the UcCode object
            it->addClassCode(classCode);
            return; // Exit the loop once class code is added
        }
    }

    // If no matching UcCode object is found, create a new one
    cPerUc.push_back(UcCode(ucCode, {classCode}));
}

list<UcCode> &ClassesPerUc::getClassesPerUc() {
    return this->cPerUc;
}

void ClassesPerUc::printData() {
    if(cPerUc.empty()){
        std::cout << "ClassesPerUc list is empty" << std::endl;
    }

    for (UcCode uc : cPerUc) {
        if(uc.getUcCode() == "UcCode"){
            continue;
        }

        std::cout << "UcCode: " << uc.getUcCode() << std::endl;

        std::list<ClassCode>& classCodes = uc.getClassCodes();
        std::cout << "Class Codes: ";
        for (ClassCode& code : classCodes) {
            std::cout << code.getCode() << " ";
        }
        std::cout << std::endl;

        std::cout << "-----------------------------------" << std::endl;
    }
}

UcCode ClassesPerUc::getUcCodebyCode(UcCode ucCode) {
    for(UcCode uc_Code : cPerUc){
        if(uc_Code.getUcCode() == ucCode.getUcCode()){
            return uc_Code;
        }
    }
}

ClassCode ClassesPerUc::getVerifyClassCode(ClassCode unVerifiedClassCode) {
    for(UcCode uc_Code : cPerUc){
        for(ClassCode class_Code : uc_Code.getClassCodes()){
            if(unVerifiedClassCode.getCode() == class_Code.getCode()){
                return class_Code;
            }
        }
    }
    return ClassCode();
}

UcCode* ClassesPerUc::findUcCodeByCode(const string& ucCode) {
    for (UcCode& uc : cPerUc) {
        if (uc.getUcCode() == ucCode) {
            return &uc; // Return a pointer to the found UC code
        }
    }
    return nullptr; // Return nullptr if the UC code is not found
}
