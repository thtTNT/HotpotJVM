//
// Created by 屠昊天 on 2022/3/16.
//

#include "Ldc.h"
#include "../../heap/StringPool.h"

void ldc(Frame *frame, unsigned index) {
    auto stack = frame->operandStack;
    auto clazz = frame->getMethod()->getClass();
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto constant = constantPool->getConstant(index);
    switch (constant.type) {
        case heap::INT:
            stack->pushInt(constant.intValue);
            break;
        case heap::FLOAT:
            stack->pushFloat(constant.floatValue);
            break;
        case heap::STRING: {
            auto internedStr = heap::JString(clazz->loader, constant.stringValue);
            stack->pushRef(internedStr);
            break;
        }
        case heap::CLASS:
            // TODO
            break;
        default:
            // TODO
            break;
    }
}

void LDC::execute(Frame *frame) {
    ldc(frame, this->index);
}

void LDC_W::execute(Frame *frame) {
    ldc(frame, this->index);
}

void LDC2_W::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto constant = constantPool->getConstant(this->index);
    switch (constant.type) {
        case heap::LONG:
            stack->pushLong(constant.longValue);
            break;
        case heap::DOUBLE:
            stack->pushDouble(constant.doubleValue);
            break;
        default:
            // TODO
            break;
    }
}
