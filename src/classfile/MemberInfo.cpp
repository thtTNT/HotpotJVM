//
// Created by 屠昊天 on 2022/3/8.
//

#include "MemberInfo.h"
#include "attribute/CodeAttribute.h"

#include <utility>

namespace classFile {
    unsigned short MemberInfo::getAccessFlags() const {
        return this->accessFlags;
    }

    std::string MemberInfo::getName() {
        return this->constantPool->getUTF8(this->nameIndex);
    }

    MemberInfo::MemberInfo(ConstantPool *constantPool, unsigned short accessFlags, unsigned short nameIndex,
                           unsigned short descriptorIndex, std::vector<AttributeInfo *> attributes) :
            constantPool(constantPool), accessFlags(accessFlags), nameIndex(nameIndex),
            descriptorIndex(descriptorIndex),
            attributes(std::move(attributes)) {}

    std::string MemberInfo::getDescriptor() {
        return this->constantPool->getUTF8(this->descriptorIndex);
    }

    CodeAttribute *MemberInfo::getCodeAttribute() {
        for (auto attribute: this->attributes) {
            if (attribute->type == CODE) {
                return dynamic_cast<CodeAttribute *>(attribute);
            }
        }
        return nullptr;
    }

    ConstantValueAttribute *MemberInfo::getConstantValueAttribute() {
        for (auto attributeInfo: this->attributes) {
            if (attributeInfo->type == CONSTANT_VALUE) {
                return (ConstantValueAttribute *) attributeInfo;
            }
        }
        return nullptr;
    }


    std::vector<MemberInfo *> readMembers(ClassReader *reader, ConstantPool *constantPool) {
        auto count = reader->readUint16();
        auto members = std::vector<MemberInfo *>(count);
        for (int i = 0; i < count; i++) {
            members[i] = readMember(reader, constantPool);
        }
        return members;
    }

    MemberInfo *readMember(ClassReader *reader, ConstantPool *constantPool) {
        return new MemberInfo(
                constantPool,
                reader->readUint16(),
                reader->readUint16(),
                reader->readUint16(),
                readAttributes(reader, constantPool)
        );
    }
}
