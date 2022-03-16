//
// Created by 屠昊天 on 2022/3/16.
//

#include "InstanceOf.h"

void INSTANCE_OF::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    if (ref == nullptr) {
        stack->pushInt(0);
        return;
    }
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto classRef = (heap::ClassRef *) constantPool->getConstant(this->index).symRef;
    auto clazz = classRef->resolvedClass();
    if (ref->isInstanceOf(clazz)) {
        stack->pushInt(1);
    } else {
        stack->pushInt(0);
    }
}
