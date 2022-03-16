//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_THREAD_H
#define HOTPOTJVM_THREAD_H


#include "Stack.h"
#include <string>

class Thread {
private:
    unsigned int pc;
    Stack *stack = newStack(1024);
public:

    unsigned int getPC();

    void setPC(unsigned int pc);

    void pushFrame(Frame *frame);

    Frame *popFrame();

    Frame *currentFrame();

    Frame *initFrame(heap::Method *method);

};

[[noreturn]] void loop(Thread *thread, std::string bytecode);

Thread *newThread();


#endif //HOTPOTJVM_THREAD_H
