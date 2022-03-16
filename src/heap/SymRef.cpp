//
// Created by 屠昊天 on 2022/3/15.
//

#include "SymRef.h"
#include "Class.h"
#include "Field.h"
#include "../exception/IllegalAccessError.h"
#include "../exception/NoSuchFieldError.h"

heap::ClassRef *heap::newClassRef(heap::ConstantPool *constantPool, classFile::ConstantClassInfo classInfo) {
    auto ref = new ClassRef();
    ref->constantPool = constantPool;
    ref->className = classInfo.getName();
    return ref;
}

heap::FieldRef *heap::newFieldRef(heap::ConstantPool *constantPool, classFile::ConstantFieldRefInfo refInfo) {
    auto ref = new FieldRef();
    ref->constantPool = constantPool;
    ref->copyMemberRefInfo(refInfo);
    return ref;
}

heap::MemberRef *heap::newMethodRef(heap::ConstantPool *constantPool, classFile::ConstantMethodRefInfo refInfo) {
    auto ref = new MethodRef();
    ref->constantPool = constantPool;
    ref->copyMemberRefInfo(refInfo);
    return ref;
}

heap::InterfaceMethodRef *
heap::newInterfaceMethodRef(heap::ConstantPool *constantPool, classFile::ConstantInterfaceMethodRefInfo refInfo) {
    auto ref = new InterfaceMethodRef();
    ref->constantPool = constantPool;
    ref->copyMemberRefInfo(refInfo);
    return ref;
}

void heap::MemberRef::copyMemberRefInfo(classFile::ConstantMemberRefInfo refInfo) {
    this->className = refInfo.getClassName();
    this->name = refInfo.getName();
    this->description = refInfo.getDescription();
}

const std::string &heap::MemberRef::getName() const {
    return name;
}

const std::string &heap::MemberRef::getDescription() const {
    return description;
}

heap::Class *heap::SymRef::resolvedClass() {
    if (this->clazz == nullptr) {
        this->resolveClassRef();
    }
    return this->clazz;
}

void heap::SymRef::resolveClassRef() {
    heap::Class *source = this->constantPool->clazz;
    auto dest = source->loader->loadClass(this->className);
    if (!dest->isAccessibleTo(source)) {
        throw IllegalAccessError();
    }
    this->clazz = dest;
}

heap::Field *heap::FieldRef::resolvedField() {
    if (this->field == nullptr) {
        this->resolveFieldRef();
    }
    return this->field;
}

void heap::FieldRef::resolveFieldRef() {
    auto source = this->constantPool->clazz;
    auto dest = this->resolvedClass();
    auto destField = lookupField(dest, this->getName(), this->getDescription());
    if (destField == nullptr) {
        throw NoSuchFieldError();
    }
    if (!destField->isAccessibleTo(source)) {
        throw IllegalAccessError();
    }
    this->field = destField;
}

heap::Field *heap::FieldRef::lookupField(Class *destClazz, std::string name, std::string descriptor) {
    for (auto tempField: destClazz->fields) {
        if (tempField->name == name && tempField->descriptor == descriptor) {
            return tempField;
        }
    }
    for (auto interface: destClazz->interfaceClass) {
        return lookupField(interface, name, descriptor);
    }
    if (destClazz->superClass != nullptr) {
        return lookupField(destClazz->superClass, name, descriptor);
    }
    return nullptr;

}
