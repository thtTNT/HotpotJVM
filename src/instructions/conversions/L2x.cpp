//
// Created by 屠昊天 on 2022/3/13.
//

#include "L2x.h"

void L2I::execute(Frame *frame) {
    auto value = frame->operandStack->popLong();
    frame->operandStack->pushInt((int) value);
}


void L2F::execute(Frame *frame) {
    auto value = frame->operandStack->popLong();
    frame->operandStack->pushFloat((float) value);
}


void L2D::execute(Frame *frame) {
    auto value = frame->operandStack->popLong();
    frame->operandStack->pushDouble((double) value);
}
