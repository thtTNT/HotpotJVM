//
// Created by 屠昊天 on 2022/3/8.
//

#include "AttributeInfo.h"
#include "attribute/CodeAttribute.h"
#include "attribute/ConstantValueAttribute.h"
#include "attribute/DeprecatedAttribute.h"
#include "attribute/ExceptionsAttribute.h"
#include "attribute/LineNumberTableAttribute.h"
#include "attribute/SourceFileAttribute.h"
#include "attribute/SyntheticAttribute.h"
#include "attribute/UnparsedAttribute.h"

std::vector<AttributeInfo *> readAttributes(ClassReader *reader, ConstantPool *constantPool) {
    auto count = reader->readUint16();
    std::vector<AttributeInfo *> attributes = std::vector<AttributeInfo *>(count);
    for (int i = 0; i < count; i++) {
        attributes[i] = readAttribute(reader, constantPool);
    }
    return attributes;
}

AttributeInfo *readAttribute(ClassReader *reader, ConstantPool *constantPool) {
    auto nameIndex = reader->readUint16();
    auto name = constantPool->getUTF8(nameIndex);
    auto len = reader->readUint32();
    auto info = newAttributeInfo(name, len, constantPool);
    info->readInfo(reader);
    return info;
}

AttributeInfo *newAttributeInfo(std::string name, unsigned int length, ConstantPool *constantPool) {
    if (name == "Code") {
        return new CodeAttribute(constantPool);
    } else if (name == "ConstantValue") {
        return new ConstantValueAttribute();
    } else if (name == "Deprecated") {
        return new DeprecatedAttribute();
    } else if (name == "Exceptions") {
        return new ExceptionsAttribute();
    } else if (name == "LineNumberTable") {
        return new LineNumberTableAttribute();
    } else if (name == "Sourcefile") {
        return new SourceFileAttribute(constantPool);
    } else if (name == "Synthetic") {
        return new SyntheticAttribute();
    } else {
        return new UnparsedAttribute(name, length);
    }
}

