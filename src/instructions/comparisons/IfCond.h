//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IFCOND_H
#define HOTPOTJVM_IFCOND_H


#include "../base/Instruction.h"

class IFEQ : public BranchInstruction {
    void execute(Frame *frame);
};

class IFNE : public BranchInstruction {
    void execute(Frame *frame);
};

class IFLT : public BranchInstruction {
    void execute(Frame *frame);
};

class IFLE : public BranchInstruction {
    void execute(Frame *frame);
};

class IFGT : public BranchInstruction {
    void execute(Frame *frame);
};

class IFGE : public BranchInstruction {
    void execute(Frame *frame);
};


#endif //HOTPOTJVM_IFCOND_H
