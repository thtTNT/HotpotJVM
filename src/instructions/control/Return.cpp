//
// Created by 屠昊天 on 2022/3/18.
//

#include "Return.h"
#include "../../rtda/Thread.h"

void RETURN::execute(Frame *frame) {
    frame->thread->popFrame();
}

void DRETURN::execute(Frame *frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto value = currentFrame->operandStack->popDouble();
    invokerFrame->operandStack->pushDouble(value);
}

void ARETURN::execute(Frame *frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto value = currentFrame->operandStack->popRef();
    invokerFrame->operandStack->pushRef(value);
}

void FRETURN::execute(Frame *frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto value = currentFrame->operandStack->popFloat();
    invokerFrame->operandStack->pushFloat(value);
}

void IRETURN::execute(Frame *frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto value = currentFrame->operandStack->popInt();
    invokerFrame->operandStack->pushInt(value);
}

void LRETURN::execute(Frame *frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto value = currentFrame->operandStack->popLong();
    invokerFrame->operandStack->pushLong(value);
}
