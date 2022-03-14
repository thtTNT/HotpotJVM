//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_LOOKUPSWITCH_H
#define HOTPOTJVM_LOOKUPSWITCH_H

#include <vector>
#include "../base/Instruction.h"

class LOOKUP_SWITCH : public Instruction{
private:
    int defaultOffset;
    int nPairs;
    std::vector<int> matchOffsets;
public:
    void fetchOperands(ByteCodeReader *reader) override;
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_LOOKUPSWITCH_H
