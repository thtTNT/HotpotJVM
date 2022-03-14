//
// Created by 屠昊天 on 2022/3/13.
//

#include "IfICmp.h"
#include "../base/BranchLogic.h"

void IF_ICMPEQ::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 == op2) {
        branch(frame, this->offset);
    }
}

void IF_ICMPNE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 != op2) {
        branch(frame, this->offset);
    }
}

void IF_ICMPLT::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 < op2) {
        branch(frame, this->offset);
    }
}

void IF_ICMPLE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 <= op2) {
        branch(frame, this->offset);
    }
}

void IF_ICMPGT::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 > op2) {
        branch(frame, this->offset);
    }
}

void IF_ICMPGE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popInt();
    auto op1 = stack->popInt();
    if (op1 >= op2) {
        branch(frame, this->offset);
    }
}
