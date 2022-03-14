//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_DUP_H
#define HOTPOTJVM_DUP_H


#include "../base/Instruction.h"

class DUP : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DUP_X1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DUP_X2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DUP2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DUP2_X1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DUP2_X2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_DUP_H
