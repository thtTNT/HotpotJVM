//
// Created by 屠昊天 on 2022/3/13.
//

#include "Interpreter.h"
#include "rtda/Thread.h"

void interpret(heap::Method *method) {
    auto thread = newThread();
    auto frame = thread->initFrame(method);
    thread->pushFrame(frame);
    loop(thread, method->code);
}
