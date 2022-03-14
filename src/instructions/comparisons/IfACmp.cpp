//
// Created by 屠昊天 on 2022/3/13.
//

#include "IfACmp.h"
#include "../base/BranchLogic.h"

void IF_ACMPEQ::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popRef();
    auto op1 = stack->popRef();
    if (op1 == op2) {
        branch(frame, this->offset);
    }
}

void IF_ACMPNE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto op2 = stack->popRef();
    auto op1 = stack->popRef();
    if (op1 != op2) {
        branch(frame, this->offset);
    }
}
