//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_AND_H
#define HOTPOTJVM_AND_H


#include "../base/Instruction.h"

class IAND : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LAND : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_AND_H
