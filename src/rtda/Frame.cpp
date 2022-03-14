//
// Created by 屠昊天 on 2022/3/11.
//

#include "Frame.h"

Frame::Frame(Thread *thread, unsigned int maxLocals, unsigned int maxStack) {
    this->thread = thread;
    this->localVars = newLocalVars(maxLocals);
    this->operandStack = newOperandStack(maxStack);
}

Frame *newFrame(Thread *thread, unsigned int maxLocals, unsigned int maxStack) {
    return new Frame(thread, maxLocals, maxStack);
}
