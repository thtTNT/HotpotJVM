//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_DLOAD_H
#define HOTPOTJVM_DLOAD_H

#include "../base/Instruction.h"

class DLOAD : public Index8Instruction {
    void execute(Frame *frame) override;
};

class DLOAD_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DLOAD_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DLOAD_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DLOAD_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_DLOAD_H
