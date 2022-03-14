//
// Created by 屠昊天 on 2022/3/13.
//

#include "Swap.h"

void SWAP::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    stack->pushSlot(slot1);
    stack->pushSlot(slot2);
}
