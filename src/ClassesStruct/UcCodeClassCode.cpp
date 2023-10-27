//
// Created by alex2 on 21.10.2023.
//

#include "UcCodeClassCode.h"

string UcCodeClassCode::GetUcCode() {
    return ucCode;
}

void UcCodeClassCode::SetUcCode(string ucCode) {
    this->ucCode= ucCode;
}

bool UcCodeClassCode::operator<(const UcCodeClassCode &code) const {
    return this->ucCode < code.ucCode;
}

void UcCodeClassCode::addClassCode(string leic) {
    this->classCode.push_back(leic);
}

UcCodeClassCode::UcCodeClassCode(string _ucCode, list<string> classCode) {
    this->ucCode = _ucCode;
    if(this->classCode.empty()){
        this->classCode = classCode;
    } else{
        this->classCode.merge(classCode);
    }
}

