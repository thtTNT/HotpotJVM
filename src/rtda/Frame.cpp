//
// Created by 屠昊天 on 2022/3/11.
//

#include "Frame.h"

Frame::Frame(Thread *thread, heap::Method *method) {
    this->thread = thread;
    this->method = method;
    this->localVars = newLocalVars(method->maxLocals);
    this->operandStack = newOperandStack(method->maxStack);
}

heap::Method *Frame::getMethod() const {
    return method;
}
