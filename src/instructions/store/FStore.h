//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_FSTORE_H
#define HOTPOTJVM_FSTORE_H

#include "../base/Instruction.h"

class FSTORE : public Index8Instruction {
    void execute(Frame *frame) override;
};

class FSTORE_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FSTORE_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FSTORE_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FSTORE_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_FSTORE_H
