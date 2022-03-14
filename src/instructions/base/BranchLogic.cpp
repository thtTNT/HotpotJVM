//
// Created by 屠昊天 on 2022/3/13.
//

#include "BranchLogic.h"

void branch(Frame *frame, int offset) {
    auto pc = frame->thread->getPC();
    pc += offset;
    frame->nextPC = pc;
}
