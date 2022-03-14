//
// Created by 屠昊天 on 2022/3/13.
//

#include "Xor.h"

void IXOR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    auto result = v1 xor v2;
    stack->pushInt(result);
}

void LXOR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    auto result = v1 xor v2;
    stack->pushLong(result);
}