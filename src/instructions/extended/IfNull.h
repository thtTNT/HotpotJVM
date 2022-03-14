//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IFNULL_H
#define HOTPOTJVM_IFNULL_H


#include "../base/Instruction.h"

class IFNULL : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IFNONNULL : public BranchInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_IFNULL_H
