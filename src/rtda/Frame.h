//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_FRAME_H
#define HOTPOTJVM_FRAME_H


#include "LocalVars.h"
#include "OperandStack.h"

class Thread;

class Frame {
public:
    Frame *last = nullptr;
    LocalVars *localVars = nullptr;
    OperandStack *operandStack = nullptr;
    Thread *thread;
    int nextPC = 0;

    Frame(Thread *thread, unsigned maxLocals, unsigned maxStack);
};

Frame *newFrame(Thread *thread, unsigned int maxLocals, unsigned int maxStack);


#endif //HOTPOTJVM_FRAME_H
