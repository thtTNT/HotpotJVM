//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantNameAndTypeInfo.h"

void ConstantNameAndTypeInfo::readInfo(ClassReader *reader) {
    this->nameIndex = reader->readUint16();
    this->descriptorIndex = reader->readUint16();
}
