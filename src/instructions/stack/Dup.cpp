//
// Created by 屠昊天 on 2022/3/13.
//

#include "Dup.h"

void DUP::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
}

void DUP_X1::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
}

void DUP_X2::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot);
}

void DUP2::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    auto slot1 = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
}

void DUP2_X1::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    auto slot1 = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
}

void DUP2_X2::execute(Frame *frame) {
    auto slot = frame->operandStack->popSlot();
    auto slot1 = frame->operandStack->popSlot();
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
    frame->operandStack->pushSlot(slot1);
    frame->operandStack->pushSlot(slot);
}
