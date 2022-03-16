//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantUTF8Info.h"

namespace classFile {
    void ConstantUTF8Info::readInfo(ClassReader *reader) {
        auto length = reader->readUint16();
        auto bytes = reader->readBytes(length);
        this->value = std::string(bytes, length);
    }
}
