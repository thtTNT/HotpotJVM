//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_TABLESWITCH_H
#define HOTPOTJVM_TABLESWITCH_H


#include "../base/Instruction.h"

class TABLE_SWITCH : public Instruction {
private:
    int defaultOffset;
    int low;
    int high;
    std::vector<int> jumpOffset;
public:
    void fetchOperands(ByteCodeReader *reader) override;
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_TABLESWITCH_H
