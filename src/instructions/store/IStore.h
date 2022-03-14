//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_ISTORE_H
#define HOTPOTJVM_ISTORE_H

#include "../base/Instruction.h"

class ISTORE : public Index8Instruction {
    void execute(Frame *frame) override;
};

class ISTORE_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ISTORE_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ISTORE_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ISTORE_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_ISTORE_H
