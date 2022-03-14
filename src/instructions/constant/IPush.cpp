//
// Created by 屠昊天 on 2022/3/13.
//

#include "IPush.h"

void BIPUSH::fetchOperands(ByteCodeReader *reader) {
    this->value = reader->readInt8();
}

void BIPUSH::execute(Frame *frame) {
    frame->operandStack->pushInt(value);
}

void SIPUSH::fetchOperands(ByteCodeReader *reader) {
    this->value = reader->readInt16();
}

void SIPUSH::execute(Frame *frame) {
    frame->operandStack->pushInt(value);
}


