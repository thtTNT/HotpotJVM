//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantDoubleInfo.h"

void ConstantDoubleInfo::readInfo(ClassReader *reader) {
    auto data = reader->readUint64();
    this->value = *(double *) &data;
}
