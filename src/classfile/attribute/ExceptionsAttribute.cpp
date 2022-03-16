//
// Created by 屠昊天 on 2022/3/11.
//

#include "ExceptionsAttribute.h"

namespace classFile {
    void ExceptionsAttribute::readInfo(ClassReader *reader) {
        this->indexTable = reader->readUint16s();
    }

    std::vector<unsigned short> ExceptionsAttribute::getIndexTable() {
        return this->indexTable;
    }

    ExceptionsAttribute::ExceptionsAttribute() : AttributeInfo(EXCEPTIONS) {

    }
}