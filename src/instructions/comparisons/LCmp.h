//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_LCMP_H
#define HOTPOTJVM_LCMP_H


#include "../base/Instruction.h"

class LCMP : public NoOperandsInstruction{
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_LCMP_H
