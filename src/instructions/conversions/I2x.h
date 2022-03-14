//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_I2X_H
#define HOTPOTJVM_I2X_H


#include "../base/Instruction.h"

class I2L : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class I2D : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class I2F : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_I2X_H
