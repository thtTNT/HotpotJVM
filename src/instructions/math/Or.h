//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_OR_H
#define HOTPOTJVM_OR_H

#include "../base/Instruction.h"

class IOR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LOR : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_OR_H
