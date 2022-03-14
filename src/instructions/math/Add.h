//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_ADD_H
#define HOTPOTJVM_ADD_H

#include "../base/Instruction.h"

class DADD : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FADD : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IADD : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LADD : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_ADD_H
