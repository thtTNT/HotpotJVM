//
// Created by 屠昊天 on 2022/3/13.
//

#include "D2x.h"

void D2F::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popDouble();
    frame->operandStack->pushFloat((float) value);
}

void D2I::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popDouble();
    frame->operandStack->pushInt((int) value);
}


void D2L::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popDouble();
    frame->operandStack->pushLong((long) value);
}
