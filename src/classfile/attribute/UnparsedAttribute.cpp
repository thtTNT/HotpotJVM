//
// Created by 屠昊天 on 2022/3/11.
//

#include "UnparsedAttribute.h"

#include <utility>

namespace classFile {
    void UnparsedAttribute::readInfo(ClassReader *reader) {
        this->info = reader->readBytes(this->length);
    }

    UnparsedAttribute::UnparsedAttribute(std::string name, unsigned int length) : AttributeInfo(UNPARSED) {
        this->name = std::move(name);
        this->length = length;
    }
}
