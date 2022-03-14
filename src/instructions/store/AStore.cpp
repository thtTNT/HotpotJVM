//
// Created by 屠昊天 on 2022/3/13.
//

#include "AStore.h"

void astore(Frame *frame, unsigned index) {
    auto value = frame->operandStack->popRef();
    frame->localVars->setObject(index, value);
}

void ASTORE::execute(Frame *frame) {
    astore(frame, this->index);
}

void ASTORE_0::execute(Frame *frame) {
    astore(frame, 0);
}

void ASTORE_1::execute(Frame *frame) {
    astore(frame, 1);
}

void ASTORE_2::execute(Frame *frame) {
    astore(frame, 2);
}

void ASTORE_3::execute(Frame *frame) {
    astore(frame, 3);
}