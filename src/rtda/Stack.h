//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_STACK_H
#define HOTPOTJVM_STACK_H


#include "Frame.h"

class Stack {
private:
    unsigned int maxSize;
    unsigned int size = 0;
    Frame *top = nullptr;
public:
    explicit Stack(unsigned int maxSize);

    void push(Frame *frame);

    Frame *pop();

    Frame *getTop();

    bool isEmpty();
};

Stack *newStack(unsigned int maxSize);


#endif //HOTPOTJVM_STACK_H
