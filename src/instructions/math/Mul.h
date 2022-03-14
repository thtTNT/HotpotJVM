//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_MUL_H
#define HOTPOTJVM_MUL_H

#include "../base/Instruction.h"

class DMUL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FMUL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IMUL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LMUL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_MUL_H
