//
// Created by 屠昊天 on 2022/3/15.
//

#include "New.h"
#include "../../exception/InstantiationError.h"
#include "../base/MethodLogic.h"

void NEW::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getConstantPool();
    auto classRef = (heap::ClassRef *) constantPool->getConstant(this->index).symRef;
    auto clazz = classRef->resolvedClass();

    if (!clazz->isInitStarted()) {
        frame->revertNextPC();
        initClass(frame->thread, clazz);
        return;
    }

    if (clazz->isInterface() || clazz->isAbstract()) {
        throw InstantiationError();
    }
    auto ref = clazz->newObject();
    frame->operandStack->pushRef(ref);
}
