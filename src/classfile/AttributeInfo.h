//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_ATTRIBUTEINFO_H
#define HOTPOTJVM_ATTRIBUTEINFO_H

#include <vector>
#include <string>

#include "ClassReader.h"
#include "ConstantPool.h"

enum AttributeType {
    CODE,
    CONSTANT_VALUE,
    DEPRECATED,
    EXCEPTIONS,
    LINE_NUMBER_TABLE,
    SOURCE_FILE,
    SYNTHETIC,
    UNPARSED
};

namespace classFile {
    class AttributeInfo {
    public:
        AttributeType type;

        AttributeInfo(AttributeType type);

        virtual void readInfo(ClassReader *reader) = 0;
    };

    std::vector<AttributeInfo *> readAttributes(ClassReader *reader, ConstantPool *constantPool);

    AttributeInfo *readAttribute(ClassReader *reader, ConstantPool *constantPool);

    AttributeInfo *newAttributeInfo(std::string name, unsigned int length, ConstantPool *constantPool);
}

#endif //HOTPOTJVM_ATTRIBUTEINFO_H
