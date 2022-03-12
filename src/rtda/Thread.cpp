//
// Created by 屠昊天 on 2022/3/11.
//

#include "Thread.h"

unsigned int Thread::getPC() {
    return this->pc;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

void Thread::setPC(unsigned int pc) {
#pragma clang diagnostic pop
    this->pc = pc;
}

void Thread::pushFrame(Frame *frame) {
    this->stack->push(frame);
}

Frame *Thread::popFrame() {
    this->stack->pop();
}

Frame *Thread::currentFrame() {
    return this->stack->getTop();
}

Thread *newThread() {
    return new Thread();
}
