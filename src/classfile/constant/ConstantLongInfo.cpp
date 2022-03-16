//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantLongInfo.h"

namespace classFile {
    void ConstantLongInfo::readInfo(ClassReader *reader) {
        this->value = (long) reader->readUint64();
    }
}
