//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantNameAndTypeInfo.h"

namespace classFile {
    void ConstantNameAndTypeInfo::readInfo(ClassReader *reader) {
        this->nameIndex = reader->readUint16();
        this->descriptorIndex = reader->readUint16();
    }

    std::string ConstantNameAndTypeInfo::getName() {
        return this->constantPool->getUTF8(this->nameIndex);
    }

    std::string ConstantNameAndTypeInfo::getDescription() {
        return this->constantPool->getUTF8(this->descriptorIndex);
    }

    ConstantNameAndTypeInfo::ConstantNameAndTypeInfo(ConstantPool *constantPool) : ConstantInfo(
            CONSTANT_NAME_AND_TYPE) {
        this->constantPool = constantPool;
    }
}
