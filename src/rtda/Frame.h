//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_FRAME_H
#define HOTPOTJVM_FRAME_H


#include "LocalVars.h"
#include "OperandStack.h"
#include "../heap/Method.h"

class Thread;

class Frame {
private:
    heap::Method *method;
public:
    Frame *last = nullptr;
    LocalVars *localVars = nullptr;
    OperandStack *operandStack = nullptr;
    Thread *thread;
    int nextPC = 0;

    Frame(Thread *thread, heap::Method *method);

    heap::Method *getMethod() const;

    void revertNextPC();
};


#endif //HOTPOTJVM_FRAME_H
