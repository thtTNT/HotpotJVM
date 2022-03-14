//
// Created by 屠昊天 on 2022/3/13.
//

#include "Rem.h"
#include "../../exception/ArithmeticExpcetion.h"
#include <cmath>

void DREM::execute(Frame *frame) {
    auto op2 = frame->operandStack->popDouble();
    auto op1 = frame->operandStack->popDouble();
    auto result = fmod(op1, op2);
    frame->operandStack->pushDouble(result);
}

void FREM::execute(Frame *frame) {
    auto op2 = frame->operandStack->popFloat();
    auto op1 = frame->operandStack->popFloat();
    auto result = fmodf(op1, op2);
    frame->operandStack->pushFloat(result);
}

void IREM::execute(Frame *frame) {
    auto op2 = frame->operandStack->popInt();
    auto op1 = frame->operandStack->popInt();
    if (op2 == 0) {
        throw ArithmeticException();
    }
    auto result = op1 % op2;
    frame->operandStack->pushInt(result);
}

void LREM::execute(Frame *frame) {
    auto op2 = frame->operandStack->popLong();
    auto op1 = frame->operandStack->popLong();
    if (op2 == 0) {
        throw ArithmeticException();
    }
    auto result = op1 % op2;
    frame->operandStack->pushLong(result);
}
