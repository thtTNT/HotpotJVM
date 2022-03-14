//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_L2X_H
#define HOTPOTJVM_L2X_H

#include "../base/Instruction.h"

class L2I : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class L2F : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class L2D : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_L2X_H
