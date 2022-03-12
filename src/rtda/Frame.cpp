//
// Created by 屠昊天 on 2022/3/11.
//

#include "Frame.h"

Frame::Frame(unsigned int maxLocals, unsigned int maxStack) {
    this->localVars = newLocalVars(maxLocals);
    this->operandStack = newOperandStack(maxStack);
}

Frame *newFrame(unsigned int maxLocals, unsigned int maxStack) {
    return new Frame(maxLocals, maxStack);
}
