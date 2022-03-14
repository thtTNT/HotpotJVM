//
// Created by 屠昊天 on 2022/3/13.
//

#include "And.h"

void IAND::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    auto result = v1 & v2;
    stack->pushInt(result);
}

void LAND::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    auto result = v1 & v2;
    stack->pushLong(result);
}
