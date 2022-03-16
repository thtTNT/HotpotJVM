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

Thread *newThread() {
    return new Thread();
}

[[noreturn]] void loop(Thread *thread, std::string bytecode) {
    auto frame = thread->popFrame();
    auto reader = new ByteCodeReader();
    while (true) {
        auto pc = frame->nextPC;
        thread->setPC(pc);
        reader->reset(bytecode, pc);
        auto opcode = reader->readUint8();
        auto ins = newInstruction(opcode);
        ins->fetchOperands(reader);
        frame->nextPC = reader->pc;
        ins->execute(frame);
    }
}
