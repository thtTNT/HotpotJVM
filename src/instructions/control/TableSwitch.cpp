//
// Created by 屠昊天 on 2022/3/13.
//

#include "TableSwitch.h"
#include "../base/BranchLogic.h"

void TABLE_SWITCH::fetchOperands(ByteCodeReader *reader) {
    reader->skipPadding();
    this->defaultOffset = reader->readInt32();
    this->low = reader->readInt32();
    this->high = reader->readInt32();
    auto jumpOffsetCount = this->high - this->low + 1;
    this->jumpOffset = reader->readInt32s(jumpOffsetCount);
}

void TABLE_SWITCH::execute(Frame *frame) {
    auto index = frame->operandStack->popInt();
    int offset;
    if (index >= this->low && index <= this->high) {
        offset = int(this->jumpOffset[index - this->low]);
    } else {
        offset = int(this->defaultOffset);
    }
    branch(frame, offset);
}
