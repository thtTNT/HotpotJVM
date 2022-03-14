//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_DIV_H
#define HOTPOTJVM_DIV_H


#include "../base/Instruction.h"

class DDIV : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FDIV : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IDIV : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LDIV : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_DIV_H
