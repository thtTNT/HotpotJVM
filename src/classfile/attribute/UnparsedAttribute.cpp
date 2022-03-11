//
// Created by 屠昊天 on 2022/3/11.
//

#include "UnparsedAttribute.h"

#include <utility>

void UnparsedAttribute::readInfo(ClassReader *reader) {
    this->info = reader->readBytes(this->length);
}

UnparsedAttribute::UnparsedAttribute(std::string name, unsigned int length) {
    this->name = std::move(name);
    this->length = length;
}

