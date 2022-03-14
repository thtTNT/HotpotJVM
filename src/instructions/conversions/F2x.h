//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_F2X_H
#define HOTPOTJVM_F2X_H


#include "../base/Instruction.h"

class F2I : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};

class F2D : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};

class F2L : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_F2X_H
