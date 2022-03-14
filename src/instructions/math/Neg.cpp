//
// Created by 屠昊天 on 2022/3/13.
//

#include "Neg.h"

void DNEG::execute(Frame *frame) {
    auto op = frame->operandStack->popDouble();
    frame->operandStack->pushDouble(op * -1);
}

void FNEG::execute(Frame *frame) {
    auto op = frame->operandStack->popFloat();
    frame->operandStack->pushFloat(op * -1);
}

void INEG::execute(Frame *frame) {
    auto op = frame->operandStack->popInt();
    frame->operandStack->pushInt(op * -1);
}

void LNEG::execute(Frame *frame) {
    auto op = frame->operandStack->popLong();
    frame->operandStack->pushLong(op * -1);
}