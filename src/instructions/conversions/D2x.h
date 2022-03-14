//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_D2X_H
#define HOTPOTJVM_D2X_H

#include "../base/Instruction.h"

class D2F : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class D2I : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class D2L : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_D2X_H
