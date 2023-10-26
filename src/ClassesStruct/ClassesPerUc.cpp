//
// Created by alex2 on 21.10.2023.
//

#include "ClassesPerUc.h"

ClassesPerUc::ClassesPerUc() = default;
ClassesPerUc::ClassesPerUc(string ucCode,string classCode){
    SetUcCode(ucCode);
}

string ClassesPerUc::GetUcCode() {
    return ucCode;
}

void ClassesPerUc::SetUcCode(string ucCode) {
    ucCode = ucCode;
}

bool ClassesPerUc::operator<(const ClassesPerUc &code) const {
    return this->ucCode < code.ucCode;
}

