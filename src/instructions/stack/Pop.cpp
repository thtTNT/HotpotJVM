//
// Created by 屠昊天 on 2022/3/13.
//

#include "Pop.h"

void POP::execute(Frame *frame) {
    frame->operandStack->popSlot();
}

void POP2::execute(Frame *frame) {
    frame->operandStack->popSlot();
    frame->operandStack->popSlot();
}
