//
// Created by 屠昊天 on 2022/3/13.
//

#include "IfNull.h"
#include "../base/BranchLogic.h"

void IFNULL::execute(Frame *frame) {
    auto ref = frame->operandStack->popRef();
    if (ref == nullptr) {
        branch(frame, this->offset);
    }
}

void IFNONNULL::execute(Frame *frame) {
    auto ref = frame->operandStack->popRef();
    if (ref != nullptr) {
        branch(frame, this->offset);
    }
}
