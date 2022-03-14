//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_LLOAD_H
#define HOTPOTJVM_LLOAD_H

#include "../base/Instruction.h"

class LLOAD : public Index8Instruction {
    void execute(Frame *frame) override;
};

class LLOAD_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LLOAD_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LLOAD_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LLOAD_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_LLOAD_H
