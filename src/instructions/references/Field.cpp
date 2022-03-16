//
// Created by 屠昊天 on 2022/3/16.
//

#include "Field.h"
#include "../../heap/Field.h"
#include "../../exception/IncompatibleClassChangeError.h"
#include "../../exception/IllegalAccessError.h"
#include "../../exception/NullPointerException.h"

void PUT_FIELD::execute(Frame *frame) {
    auto currentMethod = frame->getMethod();
    auto currentClass = currentMethod->getClass();
    auto constantPool = currentClass->constantPool;
    auto fieldRef = (heap::FieldRef *) constantPool->getConstant(this->index).symRef;
    heap::Field *field = fieldRef->resolvedField();

    if (field->isStatic()) {
        throw IncompatibleClassChangeError();
    }
    if (field->isFinal()) {
        if (currentClass != field->clazz || currentMethod->name != "<init>") {
            throw IllegalAccessError();
        }
    }

    auto descriptor = field->descriptor;
    auto slotId = field->slotId;
    auto stack = frame->operandStack;
    switch (descriptor[0]) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I': {
            auto value = stack->popInt();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                throw NullPointerException();
            }
            ref->getFields()->setInt(slotId, value);
            break;
        }
        case 'F': {
            auto value = stack->popFloat();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                throw NullPointerException();
            }
            ref->getFields()->setFloat(slotId, value);
            break;
        }
        case 'J': {
            auto value = stack->popLong();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                throw NullPointerException();
            }
            ref->getFields()->setLong(slotId, value);
            break;
        }
        case 'D': {
            auto value = stack->popDouble();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                throw NullPointerException();
            }
            ref->getFields()->setDouble(slotId, value);
            break;
        }
        case 'L':
        case '[':
            auto value = stack->popRef();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                throw NullPointerException();
            }
            ref->getFields()->setRef(slotId, value);
            break;
    }
}

void GET_FIELD::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto fieldRef = (heap::FieldRef *) constantPool->getConstant(this->index).symRef;
    auto field = fieldRef->resolvedField();

    if (field->isStatic()) {
        throw IncompatibleClassChangeError();
    }

    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    if (ref == nullptr) {
        throw NullPointerException();
    }
    auto descriptor = field->descriptor;
    auto slotId = field->slotId;
    auto slots = ref->getFields();
    switch (descriptor[0]) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            stack->pushInt(slots->getInt(slotId));
            break;
        case 'F':
            stack->pushFloat(slots->getInt(slotId));
            break;
        case 'J':
            stack->pushLong(slots->getLong(slotId));
            break;
        case 'D':
            stack->pushDouble(slots->getDouble(slotId));
            break;
        case 'L':
        case '[':
            stack->pushRef(slots->getRef(slotId));
            break;
    }

}
