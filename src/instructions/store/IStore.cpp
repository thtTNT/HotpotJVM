//
// Created by 屠昊天 on 2022/3/13.
//

#include "IStore.h"

void istore(Frame *frame, unsigned index) {
    auto value = frame->operandStack->popFloat();
    frame->localVars->setFloat(index, value);
}

void ISTORE::execute(Frame *frame) {
    istore(frame, this->index);
}

void ISTORE_0::execute(Frame *frame) {
    istore(frame, 0);
}

void ISTORE_1::execute(Frame *frame) {
    istore(frame, 1);
}

void ISTORE_2::execute(Frame *frame) {
    istore(frame, 2);
}

void ISTORE_3::execute(Frame *frame) {
    istore(frame, 3);
}