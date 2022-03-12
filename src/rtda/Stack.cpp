//
// Created by 屠昊天 on 2022/3/11.
//

#include "Stack.h"
#include "../exception/StackOverFlowError.h"
#include "../exception/StackEmptyError.h"

Stack::Stack(unsigned int maxSize) {
    this->maxSize = maxSize;
}

void Stack::push(Frame *frame) {
    if (this->size >= this->maxSize) {
        throw StackOverFlowError();
    }
    if (this->top == nullptr) {
        frame->last = this->top;
    }
    this->top = frame;
    this->size++;
}

Frame *Stack::pop() {
    if (this->top == nullptr) {
        throw StackEmptyError();
    }
    auto frame = this->top;
    this->top = frame->last;
    frame->last = nullptr;
    this->size--;
    return frame;
}

Frame *Stack::getTop() {
    if (this->top == nullptr) {
        throw StackEmptyError();
    }
    return this->top;
}

Stack *newStack(unsigned int maxSize) {
    return new Stack(maxSize);
}
