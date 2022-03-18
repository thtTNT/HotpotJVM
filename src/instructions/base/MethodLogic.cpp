//
// Created by 屠昊天 on 2022/3/16.
//

#include "MethodLogic.h"
#include "../../rtda/Thread.h"
#include "../../exception/RuntimeException.h"

void invokeMethod(Frame *frame, heap::Method *method) {
    auto thread = frame->thread;
    auto newFrame = thread->initFrame(method);
    thread->pushFrame(newFrame);
    auto argsSlotCount = method->getArgSlotCount();
    if (argsSlotCount > 0) {
        for (int i = argsSlotCount - 1; i >= 0; i--) {
            auto slot = frame->operandStack->popSlot();
            newFrame->localVars->setSlot(i, slot);
        }
    }

    // TODO HACK!
    if (method->isNative()) {
        if (method->name == "registerNatives") {
            thread->popFrame();
        } else {
            throw RuntimeException("Native method not support!");
        }
    }
}

void scheduleClinit(Thread *thread, heap::Class *clazz) {
    auto clinit = clazz->getClinitMethod();
    if (clinit != nullptr) {
        auto newFrame = thread->initFrame(clinit);
        thread->pushFrame(newFrame);
    }
}

void initSuperClass(Thread *thread, heap::Class *clazz) {
    if (!clazz->isInterface()) {
        auto superClass = clazz->superClass;
        if (superClass != nullptr && !superClass->initStarted) {
            initClass(thread, superClass);
        }
    }
}

void initClass(Thread *thread, heap::Class *clazz) {
    clazz->startInit();
    scheduleClinit(thread, clazz);
    initSuperClass(thread, clazz);
}
