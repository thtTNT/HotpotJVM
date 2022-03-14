//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_DCMP_H
#define HOTPOTJVM_DCMP_H


#include "../base/Instruction.h"

class DCMPG : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DCMPL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_DCMP_H
