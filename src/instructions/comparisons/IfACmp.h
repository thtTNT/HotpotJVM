//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IFACMP_H
#define HOTPOTJVM_IFACMP_H


#include "../base/Instruction.h"

class IF_ACMPEQ : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ACMPNE : public BranchInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_IFACMP_H
