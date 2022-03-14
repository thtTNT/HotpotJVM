//
// Created by 屠昊天 on 2022/3/13.
//

#include "FLoad.h"

void fload(Frame *frame, unsigned int index) {
    auto value = frame->localVars->getFloat(index);
    frame->operandStack->pushFloat(value);
}

void FLOAD::execute(Frame *frame) {
    fload(frame, this->index);
}

void FLOAD_0::execute(Frame *frame) {
    fload(frame, 0);
}

void FLOAD_1::execute(Frame *frame) {
    fload(frame, 1);
}

void FLOAD_2::execute(Frame *frame) {
    fload(frame, 2);
}

void FLOAD_3::execute(Frame *frame) {
    fload(frame, 3);
}