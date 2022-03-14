//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_DSTORE_H
#define HOTPOTJVM_DSTORE_H

#include "../base/Instruction.h"

class DSTORE : public Index8Instruction {
    void execute(Frame *frame) override;
};

class DSTORE_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DSTORE_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DSTORE_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DSTORE_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_DSTORE_H
