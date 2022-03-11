//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_MEMBERINFO_H
#define HOTPOTJVM_MEMBERINFO_H


#include "ConstantPool.h"
#include "AttributeInfo.h"

class MemberInfo {
private:
    ConstantPool *constantPool;
    unsigned short accessFlags;
    unsigned short nameIndex;
    unsigned short descriptorIndex;
    std::vector<AttributeInfo *> attributes;

public:

    MemberInfo(ConstantPool *constantPool, unsigned short accessFlags, unsigned short nameIndex,
               unsigned short descriptorIndex, std::vector<AttributeInfo *> attributes);

    unsigned short getAccessFlags() const;

    std::string getName();

    std::string getDescriptor();
};

std::vector<MemberInfo *> readMembers(ClassReader *reader, ConstantPool *constantPool);

MemberInfo *readMember(ClassReader *reader, ConstantPool *constantPool);


#endif //HOTPOTJVM_MEMBERINFO_H