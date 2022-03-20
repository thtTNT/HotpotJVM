//
// Created by 屠昊天 on 2022/3/20.
//

#ifndef HOTPOTJVM_NATIVEREGISTRY_H
#define HOTPOTJVM_NATIVEREGISTRY_H

#include "../rtda/Frame.h"

namespace native {
    typedef void (*NativeMethod)(Frame *);

    void
    registerNativeMethod(std::string className, std::string methodName, std::string descriptor, NativeMethod method);

    NativeMethod findNativeMethod(std::string className, std::string methodName, std::string descriptor);
}


#endif //HOTPOTJVM_NATIVEREGISTRY_H
