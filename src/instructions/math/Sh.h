//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_SH_H
#define HOTPOTJVM_SH_H


#include "../base/Instruction.h"

class ISHL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ISHR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IUSHR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSHL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LSHR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LUSHR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_SH_H
