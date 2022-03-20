//
// Created by 屠昊天 on 2022/3/13.
//

#include "Interpreter.h"

void interpret(heap::Method *method, std::vector<std::string> args) {
    auto thread = newThread();
    auto frame = thread->initFrame(method);
    thread->pushFrame(frame);
    auto jArgs = createArgsArray(method->getClass()->loader, args);
    frame->localVars->setObject(0, jArgs);
    loop(thread);
}

heap::Object *createArgsArray(heap::ClassLoader *loader, std::vector<std::string> args) {
    auto stringClass = loader->loadClass("java/lang/String");
    auto argsArr = stringClass->getArrayClass()->newArray(args.size() - 1);
    auto jArgs = argsArr->getRefs();
    for (int i = 1; i < args.size(); i++) {
        (*jArgs)[i - 1] = heap::JString(loader, args[i]);
    }
    return argsArr;
}
