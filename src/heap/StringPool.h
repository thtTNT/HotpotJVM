//
// Created by 屠昊天 on 2022/3/19.
//

#ifndef HOTPOTJVM_STRINGPOOL_H
#define HOTPOTJVM_STRINGPOOL_H

#include <map>
#include "Object.h"
#include "ClassLoader.h"

namespace heap {
    class ClassLoader;

    Object *JString(ClassLoader *loader, std::string str);
}


#endif //HOTPOTJVM_STRINGPOOL_H
