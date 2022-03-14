//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_NEG_H
#define HOTPOTJVM_NEG_H


#include "../base/Instruction.h"

class DNEG : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FNEG : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class INEG : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LNEG : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_NEG_H
