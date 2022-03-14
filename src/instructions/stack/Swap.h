//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_SWAP_H
#define HOTPOTJVM_SWAP_H


#include "../base/Instruction.h"

class SWAP : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_SWAP_H
