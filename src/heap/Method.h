//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_METHOD_H
#define HOTPOTJVM_METHOD_H

#include "ClassMember.h"
#include "ConstantPool.h"
#include <string>

namespace heap {
    struct MethodDescriptor {
        std::vector<std::string> parameterTypes;
        std::string returnType;
    };

    class Method : public ClassMember {
    private:
        unsigned argSlotCount;

        void calculateArgSlotCount();

        void copyAttribute(classFile::MemberInfo *classFileMethod);

    public:
        unsigned maxStack;
        unsigned maxLocals;
        std::string code;

        Method(Class *clazz, classFile::MemberInfo *classFileMethod);

        bool isStatic();

        bool isFinal();

        bool isSynchronized();

        bool isBridge();

        bool isVarargs();

        bool isNative();

        bool isAbstract();

        bool isStrict();

        bool isSynthetic();

        unsigned getArgSlotCount();

    };

    std::vector<Method *> newMethods(Class *clazz, std::vector<classFile::MemberInfo *> classFileMethods);

    MethodDescriptor parseDescriptor(std::string descriptor);
}


#endif //HOTPOTJVM_METHOD_H
