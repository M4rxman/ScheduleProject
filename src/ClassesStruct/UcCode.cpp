//
// Created by alex2 on 21.10.2023.
//

#include "UcCode.h"

string UcCode::GetUcCode() {
    return ucCode;
}

void UcCode::SetUcCode(string ucCode) {
    this->ucCode= ucCode;
}

bool UcCode::operator<(const UcCode &code) const {
    return this->ucCode < code.ucCode;
}

void UcCode::addClassCOde(string leic) {
    this->classCode.push_back(leic);
}

UcCode::UcCode(string _ucCode, list<string> classCode) {
    this->ucCode = _ucCode;
    if(this->classCode.empty()){
        this->classCode = classCode;
    } else{
        this->classCode.merge(classCode);
    }
}

