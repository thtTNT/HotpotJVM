//
// Created by 屠昊天 on 2022/3/13.
//

#include "ALoad.h"

void aload(Frame *frame, unsigned int index) {
    auto value = frame->localVars->getObject(index);
    frame->operandStack->pushRef(value);
}

void ALOAD::execute(Frame *frame) {
    aload(frame, this->index);
}

void ALOAD_0::execute(Frame *frame) {
    aload(frame, 0);
}

void ALOAD_1::execute(Frame *frame) {
    aload(frame, 1);
}

void ALOAD_2::execute(Frame *frame) {
    aload(frame, 2);
}

void ALOAD_3::execute(Frame *frame) {
    aload(frame, 3);
}