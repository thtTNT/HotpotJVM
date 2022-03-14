//
// Created by 屠昊天 on 2022/3/13.
//

#include "GotoW.h"
#include "../base/BranchLogic.h"

void GOTO_W::fetchOperands(ByteCodeReader *reader) {
    this->offset = reader->readInt32();
}

void GOTO_W::execute(Frame *frame) {
    branch(frame, this->offset);
}
