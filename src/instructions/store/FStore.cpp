//
// Created by 屠昊天 on 2022/3/13.
//

#include "FStore.h"

void fstore(Frame *frame, unsigned index) {
    auto value = frame->operandStack->popFloat();
    frame->localVars->setFloat(index, value);
}

void FSTORE::execute(Frame *frame) {
    fstore(frame, this->index);
}

void FSTORE_0::execute(Frame *frame) {
    fstore(frame, 0);
}

void FSTORE_1::execute(Frame *frame) {
    fstore(frame, 1);
}

void FSTORE_2::execute(Frame *frame) {
    fstore(frame, 2);
}

void FSTORE_3::execute(Frame *frame) {
    fstore(frame, 3);
}