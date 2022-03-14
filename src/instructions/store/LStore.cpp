//
// Created by 屠昊天 on 2022/3/13.
//

#include "LStore.h"

void lstore(Frame *frame, unsigned index) {
    auto value = frame->operandStack->popLong();
    frame->localVars->setLong(index, value);
}

void LSTORE::execute(Frame *frame) {
    lstore(frame, this->index);
}

void LSTORE_0::execute(Frame *frame) {
    lstore(frame, 0);
}

void LSTORE_1::execute(Frame *frame) {
    lstore(frame, 1);
}

void LSTORE_2::execute(Frame *frame) {
    lstore(frame, 2);
}

void LSTORE_3::execute(Frame *frame) {
    lstore(frame, 3);
}