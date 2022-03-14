//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_POP_H
#define HOTPOTJVM_POP_H


#include "../base/Instruction.h"

class POP : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class POP2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_POP_H
