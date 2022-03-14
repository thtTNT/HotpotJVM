//
// Created by 屠昊天 on 2022/3/13.
//

#include "DLoad.h"

void dload(Frame *frame, unsigned int index) {
    auto value = frame->localVars->getDouble(index);
    frame->operandStack->pushDouble(value);
}

void DLOAD::execute(Frame *frame) {
    dload(frame, this->index);
}

void DLOAD_0::execute(Frame *frame) {
    dload(frame, 0);
}

void DLOAD_1::execute(Frame *frame) {
    dload(frame, 1);
}

void DLOAD_2::execute(Frame *frame) {
    dload(frame, 2);
}

void DLOAD_3::execute(Frame *frame) {
    dload(frame, 3);
}