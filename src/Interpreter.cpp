//
// Created by 屠昊天 on 2022/3/13.
//

#include "Interpreter.h"
#include "rtda/Thread.h"

void interpret(MemberInfo *memberInfo) {
    auto codeAttr = memberInfo->getCodeAttributes();
    auto maxLocals = codeAttr->maxLocals;
    auto maxStack = codeAttr->maxStack;
    auto byteCode = codeAttr->code;

    auto thread = newThread();
    auto frame = thread->initFrame(maxLocals, maxStack);
    thread->pushFrame(frame);
    loop(thread, byteCode);
}
