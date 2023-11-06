//
// Created by alex2 on 21.10.2023.
//
/**
 * @file UcCode.cpp
 * @brief Implementation of the UcCode class methods.
 */
#include "UcCode.h"
#include "ClassCode.h"
/**
 * @brief Get the UcCode value.
 * @return The UcCode value.
 */
string UcCode::getUcCode() {
    return ucCode;
}
/**
 * @brief Set the UcCode value.
 * @param ucCode The UcCode to set.
 */
void UcCode::SetUcCode(string ucCode) {
    this->ucCode= ucCode;
}
/**
 * @brief Less-than comparison operator for UcCode objects.
 * @param code The UcCode to compare with.
 * @return True if this UcCode is less than the other UcCode, false otherwise.
 */
bool UcCode::operator<(const UcCode &code) const {
    return this->ucCode < code.ucCode;
}
/**
 * @brief Add a ClassCode to the list of associated ClassCodes.
 * @param leic The ClassCode to add.
 */
void UcCode::addClassCode(string leic) {
    this->classCode.push_back(ClassCode(leic));
}
/**
 * @brief Constructor for the UcCode class.
 * @param _ucCode The UcCode value.
 * @param classCode The list of associated ClassCodes.
 */
UcCode::UcCode(string _ucCode, list<ClassCode> classCode) {
    this->ucCode = _ucCode;
    if(this->classCode.empty()){
        this->classCode = classCode;
    } else{
        this->classCode.merge(classCode); // fix
    }
}
/**
 * @brief Get a reference to the list of associated ClassCodes.
 * @return Reference to the list of associated ClassCodes.
 */
list<ClassCode> &UcCode::getClassCodes() {
    return this->classCode;
}

