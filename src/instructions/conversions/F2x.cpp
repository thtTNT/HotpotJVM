//
// Created by 屠昊天 on 2022/3/13.
//

#include "F2x.h"

void F2I::execute(Frame *frame) {
    auto value = frame->operandStack->popFloat();
    frame->operandStack->pushInt((int) value);
}


void F2D::execute(Frame *frame) {
    auto value = frame->operandStack->popFloat();
    frame->operandStack->pushDouble((double) value);
}


void F2L::execute(Frame *frame) {
    auto value = frame->operandStack->popFloat();
    frame->operandStack->pushLong((long) value);
}
