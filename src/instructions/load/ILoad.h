//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_ILOAD_H
#define HOTPOTJVM_ILOAD_H


#include "../base/Instruction.h"

class ILOAD : public Index8Instruction {
    void execute(Frame *frame) override;
};

class ILOAD_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ILOAD_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ILOAD_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ILOAD_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_ILOAD_H
