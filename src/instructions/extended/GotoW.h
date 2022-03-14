//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_GOTOW_H
#define HOTPOTJVM_GOTOW_H


#include "../base/Instruction.h"

class GOTO_W : public Instruction {
private:
    unsigned offset;
public:
    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_GOTOW_H
