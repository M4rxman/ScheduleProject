//
// Created by alex2 on 21.10.2023.
//

#include "ClassesPerUc.h"

ClassesPerUc::ClassesPerUc() = default;
ClassesPerUc::ClassesPerUc(string ucCode,string classCode){
    SetClassCode(classCode);
    SetUcCode(ucCode);
}

string ClassesPerUc::GetUcCode() {
    return _ucCode;
}

string ClassesPerUc::GetClassCode() {
    return _classCode;
}

void ClassesPerUc::SetUcCode(string ucCode) {
    _ucCode = ucCode;
}

void ClassesPerUc::SetClassCode(string classCode) {
    _classCode = classCode;
}

bool ClassesPerUc::operator<(const ClassesPerUc &code) const {
    return this->_ucCode < code._ucCode;
}

