//
// Created by 屠昊天 on 2022/3/13.
//

#include "FCmp.h"

void fcmp(Frame *frame, bool gFlag) {
    auto stack = frame->operandStack;
    auto op2 = stack->popFloat();
    auto op1 = stack->popFloat();
    if (op1 > op2) {
        stack->pushInt(1);
    } else if (op1 == op2) {
        stack->pushInt(0);
    } else if (op1 < op2) {
        stack->pushInt(-1);
    } else if (gFlag) {
        stack->pushInt(1);
    } else {
        stack->pushInt(-1);
    }
}

void FCMPG::execute(Frame *frame) {
    fcmp(frame, true);
}

void FCMPL::execute(Frame *frame) {
    fcmp(frame, false);
}
