//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_FLOAD_H
#define HOTPOTJVM_FLOAD_H

#include "../base/Instruction.h"

class FLOAD : public Index8Instruction {
    void execute(Frame *frame) override;
};

class FLOAD_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FLOAD_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FLOAD_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FLOAD_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_FLOAD_H
