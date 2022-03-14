//
// Created by 屠昊天 on 2022/3/13.
//

#include "IINC.h"

void IINC::fetchOperands(ByteCodeReader *reader) {
    this->index = reader->readUint8();
    this->value = static_cast<unsigned char>(reader->readInt8());
}

void IINC::execute(Frame *frame) {
    auto op = frame->localVars->getInt(this->index);
    op += this->value;
    frame->localVars->setInt(this->index, op);
}
