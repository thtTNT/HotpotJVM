//
// Created by 屠昊天 on 2022/3/13.
//

#include "Goto.h"
#include "../base/BranchLogic.h"

void GOTO::execute(Frame *frame) {
    branch(frame, this->offset);
}
