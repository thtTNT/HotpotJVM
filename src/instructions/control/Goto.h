//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_GOTO_H
#define HOTPOTJVM_GOTO_H


#include "../base/Instruction.h"

class GOTO : public BranchInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_GOTO_H
