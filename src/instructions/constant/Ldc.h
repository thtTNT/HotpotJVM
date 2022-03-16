//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_LDC_H
#define HOTPOTJVM_LDC_H

#include "../base/Instruction.h"

class LDC : public Index8Instruction {
public:
    void execute(Frame *frame) override;
};

class LDC_W : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};

class LDC2_W : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_LDC_H
