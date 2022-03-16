//
// Created by 屠昊天 on 2022/3/14.
//

#include "ClassMember.h"

using namespace heap;

void ClassMember::copyMemberInfo(classFile::MemberInfo *memberInfo) {
    this->accessFlags = memberInfo->getAccessFlags();
    this->name = memberInfo->getName();
    this->descriptor = memberInfo->getDescriptor();
}

Class *ClassMember::getClass() const {
    return clazz;
}

ConstantPool *ClassMember::getConstantPool() {
    return this->clazz->constantPool;
}
