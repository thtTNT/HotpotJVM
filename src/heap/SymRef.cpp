//
// Created by 屠昊天 on 2022/3/15.
//

#include "SymRef.h"
#include "Class.h"
#include "Field.h"
#include "Method.h"
#include "ClassLoader.h"
#include "../exception/IllegalAccessError.h"
#include "../exception/NoSuchFieldError.h"
#include "../exception/IncompatibleClassChangeError.h"
#include "../exception/NoSuchMethodError.h"

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

heap::Method *heap::MethodRef::resolvedMethod() {
    if (this->method == nullptr) {
        this->resolveMethodRef();
    }
    return this->method;
}

void heap::MethodRef::resolveMethodRef() {
    auto source = this->constantPool->clazz;
    auto dest = this->resolvedClass();
    if (dest->isInterface()) {
        throw IncompatibleClassChangeError();
    }
    auto destMethod = lookupMethod(dest, this->getName(), this->getDescription());
    if (destMethod == nullptr) {
        throw NoSuchMethodError();
    }
    if (!destMethod->isAccessibleTo(clazz)) {
        throw IllegalAccessError();
    }
    this->method = destMethod;
}

heap::Method *heap::MethodRef::lookupMethod(heap::Class *destClass, std::string methodName, std::string descriptor) {
    auto resultMethod = lookupMethodInClass(destClass, methodName, descriptor);
    if (resultMethod != nullptr) {
        return resultMethod;
    }
    return lookupMethodInInterface(destClass->interfaceClass, methodName, descriptor);
}

heap::Method *heap::lookupMethodInClass(heap::Class *destClass, std::string name, std::string descriptor) {
    for (auto targetClass = destClass; targetClass != nullptr; targetClass = targetClass->superClass) {
        for (auto targetMethod: targetClass->methods) {
            if (targetMethod->name == name && targetMethod->descriptor == descriptor) {
                return targetMethod;
            }
        }
    }
    return nullptr;
}

heap::Method *
heap::lookupMethodInInterface(std::vector<Class *> interfaces, std::string name, std::string descriptor) {
    for (auto interface: interfaces) {
        for (auto targetMethod: interface->methods) {
            if (targetMethod->name == name && targetMethod->descriptor == descriptor) {
                return targetMethod;
            }
        }
        auto targetMethod = lookupMethodInInterface(interface->interfaceClass, name, descriptor);
        if (targetMethod != nullptr) {
            return targetMethod;
        }
    }
    return nullptr;
}

heap::Method *heap::InterfaceMethodRef::resolvedInterfaceMethod() {
    if (this->method == nullptr) {
        this->resolveInterfaceMethodRef();
    }
    return this->method;
}

void heap::InterfaceMethodRef::resolveInterfaceMethodRef() {
    auto source = this->constantPool->clazz;
    auto dest = this->resolvedClass();
    if (!dest->isInterface()) {
        throw IncompatibleClassChangeError();
    }

    auto resolvedMethod = lookupInterfaceMethod(dest, this->getName(), this->getDescription());
    if (resolvedMethod == nullptr) {
        throw NoSuchMethodError();
    }

    if (!method->isAccessibleTo(source)) {
        throw IllegalAccessError();
    }

    this->method = resolvedMethod;
}

// TODO
heap::Method *heap::lookupInterfaceMethod(heap::Class *destClass, const std::string &methodName,
                                          const std::string &methodDescriptor) {
    for (auto method: destClass->methods) {
        if (method->name == methodName && method->descriptor == methodDescriptor) {
            return method;
        }
    }
    return lookupMethodInInterface(destClass->interfaceClass, methodName, methodDescriptor);
}
