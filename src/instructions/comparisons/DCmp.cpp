//
// Created by 屠昊天 on 2022/3/13.
//

#include "DCmp.h"

void dcmp(Frame *frame, bool gFlag) {
    auto stack = frame->operandStack;
    auto op2 = stack->popDouble();
    auto op1 = stack->popDouble();
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

void DCMPG::execute(Frame *frame) {
    dcmp(frame, true);
}

void DCMPL::execute(Frame *frame) {
    dcmp(frame, false);
}
