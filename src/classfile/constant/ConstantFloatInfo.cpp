//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantFloatInfo.h"

namespace classFile {
    void ConstantFloatInfo::readInfo(ClassReader *reader) {
        auto data = reader->readUint32();
        this->value = *(float *) &data;
    }
}