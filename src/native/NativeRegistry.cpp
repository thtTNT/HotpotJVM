//
// Created by 屠昊天 on 2022/3/20.
//

#include "NativeRegistry.h"
#include <map>

namespace native {

    std::map<std::string, NativeMethod> registry;

    void emptyNativeMethod(Frame *frame) {}


    void registerNativeMethod(std::string className, std::string methodName, std::string descriptor,
                              native::NativeMethod method) {
        auto key = className + "~" + methodName + "~" + descriptor;
        registry[key] = method;
    }

    NativeMethod findNativeMethod(std::string className, std::string methodName, std::string descriptor) {
        auto key = className + "~" + methodName + "~" + descriptor;
        if (registry[key] != nullptr) {
            return registry[key];
        }
        if (descriptor == "()V" && methodName == "registerNatives") {
            return emptyNativeMethod;
        }
        return nullptr;
    }


}