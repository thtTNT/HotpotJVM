//
// Created by 屠昊天 on 2022/3/13.
//

#include "Add.h"

void DADD::execute(Frame *frame) {
    auto op2 = frame->operandStack->popDouble();
    auto op1 = frame->operandStack->popDouble();
    auto result = op1 + op2;
    frame->operandStack->pushDouble(result);
}

void FADD::execute(Frame *frame) {
    auto op2 = frame->operandStack->popFloat();
    auto op1 = frame->operandStack->popFloat();
    auto result = op1 + op2;
    frame->operandStack->pushFloat(result);
}

void IADD::execute(Frame *frame) {
    auto op2 = frame->operandStack->popInt();
    auto op1 = frame->operandStack->popInt();
    auto result = op1 + op2;
    frame->operandStack->pushInt(result);
}

void LADD::execute(Frame *frame) {
    auto op2 = frame->operandStack->popLong();
    auto op1 = frame->operandStack->popLong();
    auto result = op1 + op2;
    frame->operandStack->pushLong(result);
}