//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_INSTANCEOF_H
#define HOTPOTJVM_INSTANCEOF_H


#include "../base/Instruction.h"

class INSTANCE_OF : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_INSTANCEOF_H
