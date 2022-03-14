//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_ASTORE_H
#define HOTPOTJVM_ASTORE_H

#include "../base/Instruction.h"

class ASTORE : public Index8Instruction {
    void execute(Frame *frame) override;
};

class ASTORE_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ASTORE_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ASTORE_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ASTORE_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_ASTORE_H
