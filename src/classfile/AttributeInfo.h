//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_ATTRIBUTEINFO_H
#define HOTPOTJVM_ATTRIBUTEINFO_H

#include <vector>
#include <string>

#include "ClassReader.h"
#include "ConstantPool.h"

class AttributeInfo {
public:
    virtual void readInfo(ClassReader *reader) = 0;
};

std::vector<AttributeInfo *> readAttributes(ClassReader *reader, ConstantPool *constantPool);

AttributeInfo *readAttribute(ClassReader *reader, ConstantPool *constantPool);

AttributeInfo *newAttributeInfo(std::string name, unsigned int length, ConstantPool *constantPool);

#endif //HOTPOTJVM_ATTRIBUTEINFO_H
