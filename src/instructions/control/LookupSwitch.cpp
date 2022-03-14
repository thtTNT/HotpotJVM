//
// Created by 屠昊天 on 2022/3/13.
//

#include "LookupSwitch.h"
#include "../base/BranchLogic.h"

void LOOKUP_SWITCH::fetchOperands(ByteCodeReader *reader) {
    reader->skipPadding();
    this->defaultOffset = reader->readInt32();
    this->nPairs = reader->readInt32();
    this->matchOffsets = reader->readInt32s(this->nPairs * 2);
}

void LOOKUP_SWITCH::execute(Frame *frame) {
    auto key = frame->operandStack->popInt();
    for (int i = 0; i < this->nPairs * 2; i = i + 2) {
        if (this->matchOffsets[i] == key) {
            auto offset = this->matchOffsets[i + 1];
            branch(frame, offset);
            return;
        }
    }
    branch(frame, int(this->defaultOffset));
}
