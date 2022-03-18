//
// Created by 屠昊天 on 2022/3/16.
//

#include "Static.h"
#include "../../heap/Field.h"
#include "../../exception/IncompatibleClassChangeError.h"
#include "../../exception/IllegalAccessError.h"
#include "../base/MethodLogic.h"

void PUT_STATIC::execute(Frame *frame) {
    auto currentMethod = frame->getMethod();
    auto currentClass = currentMethod->clazz;
    auto constantPool = currentClass->constantPool;
    auto fieldRef = (heap::FieldRef *) constantPool->getConstant(this->index).symRef;
    auto field = fieldRef->resolvedField();
    auto clazz = field->clazz;

    if (!clazz->isInitStarted()) {
        frame->revertNextPC();
        initClass(frame->thread, clazz);
        return;
    }

    if (!field->isStatic()) {
        throw IncompatibleClassChangeError();
    }

    if (field->isFinal()) {
        if (currentClass != clazz || currentMethod->name != "<clinit>") {
            throw IllegalAccessError();
        }
    }

    auto descriptor = field->descriptor;
    auto slotId = field->slotId;
    auto slots = clazz->staticVars;
    auto stack = frame->operandStack;

    auto chr = descriptor[0];
    switch (chr) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            slots->setInt(slotId, stack->popInt());
            break;
        case 'F':
            slots->setFloat(slotId, stack->popFloat());
            break;
        case 'J':
            slots->setLong(slotId, stack->popLong());
            break;
        case 'D':
            slots->setDouble(slotId, stack->popDouble());
            break;
        case 'L':
        case '[':
            slots->setRef(slotId, stack->popRef());
            break;
    }
}

void GET_STATIC::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto fieldRef = (heap::FieldRef *) constantPool->getConstant(this->index).symRef;
    auto field = fieldRef->resolvedField();
    auto clazz = field->clazz;

    if (!clazz->isInitStarted()) {
        frame->revertNextPC();
        initClass(frame->thread, clazz);
        return;
    }

    if (!field->isStatic()) {
        throw IncompatibleClassChangeError();
    }

    auto descriptor = field->descriptor;
    auto slotId = field->slotId;
    auto slots = clazz->staticVars;
    auto stack = frame->operandStack;

    auto chr = descriptor[0];
    switch (chr) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            stack->pushInt(slots->getInt(slotId));
            break;
        case 'F':
            stack->pushFloat(slots->getFloat(slotId));
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
