//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_WIDE_H
#define HOTPOTJVM_WIDE_H


#include "../base/Instruction.h"

class WIDE : public Instruction {
private:
    Instruction *modifiedInstruction;
public:
    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_WIDE_H
