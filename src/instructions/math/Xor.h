//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_XOR_H
#define HOTPOTJVM_XOR_H


#include "../base/Instruction.h"

class IXOR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LXOR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_XOR_H
