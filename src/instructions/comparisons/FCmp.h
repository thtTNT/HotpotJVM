//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_FCMP_H
#define HOTPOTJVM_FCMP_H


#include "../base/Instruction.h"

class FCMPG : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};

class FCMPL : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_FCMP_H
