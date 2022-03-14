//
// Created by 屠昊天 on 2022/3/13.
//

#include "IfCond.h"
#include "../base/BranchLogic.h"

void IFEQ::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value == 0) {
        branch(frame, this->offset);
    }
}

void IFNE::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value != 0) {
        branch(frame, this->offset);
    }
}

void IFLT::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value < 0) {
        branch(frame, this->offset);
    }
}

void IFLE::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value <= 0) {
        branch(frame, this->offset);
    }
}

void IFGT::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value > 0) {
        branch(frame, this->offset);
    }
}

void IFGE::execute(Frame *frame) {
    auto value = frame->operandStack->popInt();
    if (value >= 0) {
        branch(frame, this->offset);
    }
}
