//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantClassInfo.h"

namespace classFile {
    void ConstantClassInfo::readInfo(ClassReader *reader) {
        this->nameIndex = reader->readUint16();
    }

    ConstantClassInfo::ConstantClassInfo(ConstantPool *constantPool) : ConstantInfo(CONSTANT_CLASS) {
        this->constantPool = constantPool;
    }

    std::string ConstantClassInfo::getName() const {
        return this->constantPool->getUTF8(this->nameIndex);
    }
}
