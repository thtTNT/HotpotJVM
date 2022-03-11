//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantMemberRefInfo.h"

void ConstantMemberRefInfo::readInfo(ClassReader *reader) {
    this->classIndex = reader->readUint16();
    this->nameAndTypeIndex = reader->readUint16();
}

ConstantMemberRefInfo::ConstantMemberRefInfo(unsigned short type, ConstantPool *constantPool) : ConstantInfo(type) {
    this->constantPool = constantPool;
}
