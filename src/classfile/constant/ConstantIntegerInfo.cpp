//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantIntegerInfo.h"

void ConstantIntegerInfo::readInfo(ClassReader *reader) {
    this->value = (int) reader->readUint32();
}

