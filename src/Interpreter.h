//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_INTERPRETER_H
#define HOTPOTJVM_INTERPRETER_H

#include "heap/Method.h"
#include "heap/StringPool.h"
#include "rtda/Thread.h"

void interpret(heap::Method *method, std::vector<std::string> args);

heap::Object *createArgsArray(heap::ClassLoader *loader, std::vector<std::string> args);

#endif //HOTPOTJVM_INTERPRETER_H
