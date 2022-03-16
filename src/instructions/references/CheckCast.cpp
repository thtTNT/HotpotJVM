//
// Created by 屠昊天 on 2022/3/16.
//

#include "CheckCast.h"
#include "../../exception/ClassCastException.h"

void CHECK_CAST::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    stack->pushRef(ref);
    if (ref == nullptr) {
        return;
    }
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto classRef = (heap::ClassRef *) constantPool->getConstant(this->index).symRef;
    auto clazz = classRef->resolvedClass();
    if (!ref->isInstanceOf(clazz)){
        throw ClassCastException();
    }
}
