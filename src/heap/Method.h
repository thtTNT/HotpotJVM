//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_METHOD_H
#define HOTPOTJVM_METHOD_H

#include "ClassMember.h"
#include "ConstantPool.h"
#include <string>

namespace heap {
    class Method : public ClassMember {
    public:
        unsigned maxStack;
        unsigned maxLocals;
        std::string code;

        void copyAttribute(classFile::MemberInfo *classFileMethod);

        bool isPublic();

        bool isPrivate();

        bool isProtected();

        bool isStatic();

        bool isFinal();

        bool isSynchronized();

        bool isBridge();

        bool isVarargs();

        bool isNative();

        bool isAbstract();

        bool isStrict();

        bool isSynthetic();

    };

    std::vector<Method *> newMethods(Class *clazz, std::vector<classFile::MemberInfo *> classFileMethods);
}


#endif //HOTPOTJVM_METHOD_H
