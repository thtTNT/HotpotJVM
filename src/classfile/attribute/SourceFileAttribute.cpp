//
// Created by 屠昊天 on 2022/3/11.
//

#include "SourceFileAttribute.h"

void SourceFileAttribute::readInfo(ClassReader *reader) {
    this->sourceFileIndex = reader->readUint16();
}

std::string SourceFileAttribute::filename() {
    return this->constantPool->getUTF8(this->sourceFileIndex);
}

SourceFileAttribute::SourceFileAttribute(ConstantPool *constantPool) : AttributeInfo(SOURCE_FILE) {
    this->constantPool = constantPool;
}

