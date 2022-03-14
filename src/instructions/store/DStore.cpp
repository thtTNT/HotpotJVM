//
// Created by 屠昊天 on 2022/3/13.
//

#include "DStore.h"

void dstore(Frame *frame, unsigned index) {
    auto value = frame->operandStack->popDouble();
    frame->localVars->setDouble(index, value);
}

void DSTORE::execute(Frame *frame) {
    dstore(frame, this->index);
}

void DSTORE_0::execute(Frame *frame) {
    dstore(frame, 0);
}

void DSTORE_1::execute(Frame *frame) {
    dstore(frame, 1);
}

void DSTORE_2::execute(Frame *frame) {
    dstore(frame, 2);
}

void DSTORE_3::execute(Frame *frame) {
    dstore(frame, 3);
}