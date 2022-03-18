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

bool ClassMember::isAccessibleTo(Class *otherClass) {
    if (this->isPublic()) {
        return true;
    }
    if (this->isProtected()) {
        return this->clazz == otherClass || otherClass->isSubClassOf(this->clazz) ||
               this->clazz->getPackageName() == otherClass->getPackageName();
    }
    if (!this->isPrivate()) {
        return this->clazz->getPackageName() == otherClass->getPackageName();
    }
    return otherClass == this->clazz;
}

bool ClassMember::isPublic() {
    return this->accessFlags & ACC_PUBLIC;
}

bool ClassMember::isProtected() {
    return this->accessFlags & ACC_PROTECTED;
}

bool ClassMember::isPrivate() {
    return this->accessFlags & ACC_PRIVATE;
}
