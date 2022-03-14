//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_LSTORE_H
#define HOTPOTJVM_LSTORE_H

#include "../base/Instruction.h"

class LSTORE : public Index8Instruction {
    void execute(Frame *frame) override;
};

class LSTORE_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSTORE_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSTORE_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSTORE_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_LSTORE_H
