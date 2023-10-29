//
// Created by alex2 on 21.10.2023.
//

#include "UcCode.h"
#include "ClassCode.h"

string UcCode::getUcCode() {
    return ucCode;
}

void UcCode::SetUcCode(string ucCode) {
    this->ucCode= ucCode;
}

bool UcCode::operator<(const UcCode &code) const {
    return this->ucCode < code.ucCode;
}

void UcCode::addClassCode(string leic) {
    this->classCode.push_back(ClassCode(leic));
}

UcCode::UcCode(string _ucCode, list<ClassCode> classCode) {
    this->ucCode = _ucCode;
    if(this->classCode.empty()){
        this->classCode = classCode;
    } else{
        this->classCode.merge(classCode); // fix
    }
}

list<ClassCode> &UcCode::getClassCodes() {
    return this->classCode;
}

