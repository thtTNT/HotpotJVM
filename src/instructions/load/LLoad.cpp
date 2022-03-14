//
// Created by 屠昊天 on 2022/3/13.
//

#include "LLoad.h"

void lload(Frame *frame, unsigned int index) {
    auto value = frame->localVars->getLong(index);
    frame->operandStack->pushLong(value);
}

void LLOAD::execute(Frame *frame) {
    lload(frame, this->index);
}

void LLOAD_0::execute(Frame *frame) {
    lload(frame, 0);
}

void LLOAD_1::execute(Frame *frame) {
    lload(frame, 1);
}

void LLOAD_2::execute(Frame *frame) {
    lload(frame, 2);
}

void LLOAD_3::execute(Frame *frame) {
    lload(frame, 3);
}