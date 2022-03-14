//
// Created by 屠昊天 on 2022/3/13.
//

#include "I2x.h"

void I2D::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    frame->operandStack->pushDouble((double) value);
}

void I2L::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    frame->operandStack->pushLong((long) value);
}

void I2F::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    frame->operandStack->pushFloat((float) value);
}
