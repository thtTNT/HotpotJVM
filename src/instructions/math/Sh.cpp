//
// Created by 屠昊天 on 2022/3/13.
//

#include "Sh.h"

void ISHL::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    auto shift = static_cast<unsigned>(op2) & 0x1f;
    auto result = op1 << shift;
    stack->pushInt(result);
}

void ISHR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    auto shift = static_cast<unsigned>(op2) & 0x1f;
    auto result = op1 >> shift;
    stack->pushInt(result);
}

void IUSHR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    auto shift = static_cast<unsigned>(op2) & 0x1f;
    auto result = static_cast<unsigned >(op1) >> shift;
    stack->pushInt(static_cast<int>(result));
}

void LSHL::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popLong();
    auto shift = static_cast<unsigned>(op2) & 0x3f;
    auto result = op1 << shift;
    stack->pushLong(result);
}

void LSHR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popLong();
    auto shift = static_cast<unsigned>(op2) & 0x3f;
    auto result = op1 >> shift;
    stack->pushLong(result);
}

void LUSHR::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popLong();
    auto shift = static_cast<unsigned>(op2) & 0x3f;
    auto result = static_cast<unsigned >(op1) >> shift;
    stack->pushLong(static_cast<int>(result));
}
