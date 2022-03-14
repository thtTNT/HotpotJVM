//
// Created by 屠昊天 on 2022/3/13.
//

#include "ILoad.h"

void iload(Frame *frame, unsigned int index) {
    auto value = frame->localVars->getInt(index);
    frame->operandStack->pushInt(value);
}

void ILOAD::execute(Frame *frame) {
    iload(frame, this->index);
}

void ILOAD_0::execute(Frame *frame) {
    iload(frame, 0);
}

void ILOAD_1::execute(Frame *frame) {
    iload(frame, 1);
}

void ILOAD_2::execute(Frame *frame) {
    iload(frame, 2);
}

void ILOAD_3::execute(Frame *frame) {
    iload(frame, 3);
}
