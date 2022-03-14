//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_SUB_H
#define HOTPOTJVM_SUB_H

#include "../base/Instruction.h"

class DSUB : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FSUB : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ISUB : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSUB : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_SUB_H
