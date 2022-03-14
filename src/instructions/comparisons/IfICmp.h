//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IFICMP_H
#define HOTPOTJVM_IFICMP_H


#include "../base/Instruction.h"

class IF_ICMPEQ : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ICMPNE : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ICMPLT : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ICMPLE : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ICMPGT : public BranchInstruction {
    void execute(Frame *frame) override;
};

class IF_ICMPGE : public BranchInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_IFICMP_H
