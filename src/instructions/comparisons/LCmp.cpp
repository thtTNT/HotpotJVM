//
// Created by 屠昊天 on 2022/3/13.
//

#include "LCmp.h"

void LCMP::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popLong();
    auto op1 = stack->popLong();
    if (op1 > op2) {
        stack->pushInt(1);
    } else if (op1 == op2) {
        stack->pushInt(0);
    } else {
        stack->pushInt(-1);
    }
}
