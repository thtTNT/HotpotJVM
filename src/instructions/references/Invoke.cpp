//
// Created by 屠昊天 on 2022/3/16.
//

#include "Invoke.h"
#include <iostream>
#include "../../exception/IncompatibleClassChangeError.h"
#include "../base/MethodLogic.h"
#include "../../exception/NoSuchMethodError.h"
#include "../../exception/IllegalAccessError.h"
#include "../../exception/AbstractMethodError.h"
#include "../../exception/NullPointerException.h"

void INVOKE_STATIC::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto methodRef = static_cast<heap::MethodRef *>(constantPool->getConstant(this->index).symRef);
    auto method = methodRef->resolvedMethod();
    auto clazz = method->clazz;

    if (!clazz->isInitStarted()) {
        frame->revertNextPC();
        initClass(frame->thread, clazz);
        return;
    }

    if (!method->isStatic()) {
        throw IncompatibleClassChangeError();
    }
    invokeMethod(frame, method);
}

void INVOKE_SPECIAL::execute(Frame *frame) {
    auto currentClass = frame->getMethod()->getClass();
    auto constantPool = currentClass->constantPool;
    auto methodRef = static_cast<heap::MethodRef *>(constantPool->getConstant(this->index).symRef);
    auto clazz = methodRef->resolvedClass();
    auto method = methodRef->resolvedMethod();
    if (methodRef->getName() == "<init>" && method->clazz != clazz) {
        throw NoSuchMethodError();
    }
    if (method->isStatic()) {
        throw IncompatibleClassChangeError();
    }

    auto ref = frame->operandStack->getRefFromTop(method->getArgSlotCount());

    if (method->isProtected() &&
        method->clazz->isSuperClassOf(currentClass) &&
        method->clazz->getPackageName() != currentClass->getPackageName() &&
        ref->getClass() != currentClass &&
        !ref->getClass()->isSubClassOf(currentClass)) {
        throw IllegalAccessError();
    }

    auto methodToInvoke = method;
    if (currentClass->isSuper() &&
        clazz->isSuperClassOf(currentClass) &&
        method->name != "<init>") {
        methodToInvoke = heap::lookupMethodInClass(currentClass->superClass, method->name, method->descriptor);
    }

    if (methodToInvoke == nullptr || methodToInvoke->isAbstract()) {
        throw AbstractMethodError();
    }

    invokeMethod(frame, methodToInvoke);
}

void INVOKE_VIRTUAL::execute(Frame *frame) {
    auto currentClass = frame->getMethod()->getClass();
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto methodRef = (heap::MethodRef *) constantPool->getConstant(this->index).symRef;
    auto method = methodRef->resolvedMethod();
    if (method->isStatic()) {
        throw IncompatibleClassChangeError();
    }

    auto ref = frame->operandStack->getRefFromTop(method->getArgSlotCount() - 1);
    if (ref == nullptr) {
        if (methodRef->getName() == "println") {
            auto stack = frame->operandStack;
            auto descriptor = methodRef->getDescription();
            if (descriptor == "(Z)V") {
                std::cout << (stack->popInt() != 0) << std::endl;
            } else if (descriptor == "(C)V") {
                std::cout << stack->popInt() << std::endl;
            } else if (descriptor == "(B)V") {
                std::cout << stack->popInt() << std::endl;
            } else if (descriptor == "(S)V") {
                std::cout << stack->popInt() << std::endl;
            } else if (descriptor == "(I)V") {
                std::cout << stack->popInt() << std::endl;
            } else if (descriptor == "(J)V") {
                std::cout << stack->popLong() << std::endl;
            } else if (descriptor == "(F)V") {
                std::cout << stack->popFloat() << std::endl;
            } else if (descriptor == "(D)V") {
                std::cout << stack->popDouble() << std::endl;
            } else {
                std::cout << "Error Print: " << methodRef->getDescription() << std::endl;
            }
            stack->popRef();
            return;
        } else {
            throw NullPointerException();
        }
    }

    if (method->isProtected() &&
        method->clazz->isSuperClassOf(currentClass) &&
        method->clazz->getPackageName() != currentClass->getPackageName() &&
        ref->getClass() != currentClass &&
        !ref->getClass()->isSuperClassOf(currentClass)) {
        throw IllegalAccessError();
    }

    auto methodToInvoke = heap::lookupMethodInClass(ref->getClass(), methodRef->getName(), methodRef->getDescription());
    if (methodToInvoke == nullptr || methodToInvoke->isAbstract()) {
        throw AbstractMethodError();
    }

    invokeMethod(frame, methodToInvoke);
}

void INVOKE_INTERFACE::fetchOperands(ByteCodeReader *reader) {
    this->index = reader->readUint16();
}

void INVOKE_INTERFACE::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto methodRef = static_cast<heap::InterfaceMethodRef *>(constantPool->getConstant(this->index).symRef);
    auto method = methodRef->resolvedInterfaceMethod();
    if (method->isStatic() || method->isPrivate()) {
        throw IncompatibleClassChangeError();
    }

    auto ref = frame->operandStack->getRefFromTop(method->getArgSlotCount() - 1);
    if (ref == nullptr) {
        throw NullPointerException();
    }
    if (!ref->getClass()->isImplements(methodRef->resolvedClass())) {
        throw IncompatibleClassChangeError();
    }

    auto methodToInvoke = heap::lookupMethodInClass(ref->getClass(), methodRef->getName(), methodRef->getDescription());
    if (methodToInvoke == nullptr || methodToInvoke->isAbstract()) {
        throw AbstractMethodError();
    }
    if (!methodToInvoke->isPublic()) {
        throw IllegalAccessError();
    }

    invokeMethod(frame, methodToInvoke);
}


