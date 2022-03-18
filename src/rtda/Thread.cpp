//
// Created by 屠昊天 on 2022/3/11.
//

#include "Thread.h"
#include "../instructions/base/ByteCodeReader.h"
#include "../instructions/base/Instruction.h"
#include <iostream>


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
    return this->stack->pop();
}

Frame *Thread::currentFrame() {
    return this->stack->getTop();
}

Frame *Thread::initFrame(heap::Method *method) {
    return new Frame(this, method);
}

bool Thread::isStackEmpty() {
    return this->stack->isEmpty();
}

Thread *newThread() {
    return new Thread();
}

void loop(Thread *thread) {
    auto reader = new ByteCodeReader();
    while (true) {
        auto frame = thread->currentFrame();
        auto pc = frame->nextPC;
        thread->setPC(pc);
        reader->reset(frame->getMethod()->code, pc);
        auto opcode = reader->readUint8();
        auto ins = newInstruction(opcode);
        ins->fetchOperands(reader);
        frame->nextPC = reader->pc;
        ins->execute(frame);
        if (thread->isStackEmpty()) {
            return;
        }
    }
}
