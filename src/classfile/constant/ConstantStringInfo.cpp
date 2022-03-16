//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantStringInfo.h"

namespace classFile {
    ConstantStringInfo::ConstantStringInfo(ConstantPool *constantPool) : ConstantInfo(CONSTANT_STRING) {
        this->constantPool = constantPool;
    }

    void ConstantStringInfo::readInfo(ClassReader *reader) {
        this->index = reader->readUint16();
    }

    std::string ConstantStringInfo::getValue() {
        return this->constantPool->getUTF8(this->index);
    }
}
