//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_ALOAD_H
#define HOTPOTJVM_ALOAD_H

#include "../base/Instruction.h"

class ALOAD : public Index8Instruction {
    void execute(Frame *frame) override;
};

class ALOAD_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ALOAD_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ALOAD_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ALOAD_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_ALOAD_H
