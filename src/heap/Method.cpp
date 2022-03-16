//
// Created by 屠昊天 on 2022/3/14.
//

#include "Method.h"

namespace heap {
    std::vector<Method *> newMethods(Class *clazz, std::vector<classFile::MemberInfo *> classFileMethods) {
        auto methods = std::vector<Method *>(classFileMethods.size());
        for (int i = 0; i < classFileMethods.size(); i++) {
            methods[i] = new Method();
            methods[i]->clazz = clazz;
            methods[i]->copyMemberInfo(classFileMethods[i]);
            methods[i]->copyAttribute(classFileMethods[i]);
        }
        return methods;
    }

    void Method::copyAttribute(classFile::MemberInfo *classFileMethod) {
        auto codeAttribute = classFileMethod->getCodeAttribute();
        if (codeAttribute != nullptr) {
            this->maxStack = codeAttribute->maxStack;
            this->maxLocals = codeAttribute->maxLocals;
            this->code = codeAttribute->code;
        }
    }

    bool Method::isPublic() {
        return this->accessFlags & ACC_PUBLIC;
    }

    bool Method::isPrivate() {
        return this->accessFlags & ACC_PRIVATE;
    }

    bool Method::isProtected() {
        return this->accessFlags & ACC_PROTECTED;
    }

    bool Method::isStatic() {
        return this->accessFlags & ACC_STATIC;
    }

    bool Method::isFinal() {
        return this->accessFlags & ACC_FINAL;
    }

    bool Method::isSynchronized() {
        return this->accessFlags & ACC_SYNCHRONIZED;
    }

    bool Method::isBridge() {
        return this->accessFlags & ACC_BRIDGE;
    }

    bool Method::isVarargs() {
        return this->accessFlags & ACC_VARARGS;
    }

    bool Method::isNative() {
        return this->accessFlags & ACC_NATIVE;
    }

    bool Method::isAbstract() {
        return this->accessFlags & ACC_ABSTRACT;
    }

    bool Method::isStrict() {
        return this->accessFlags & ACC_STRICT;
    }

    bool Method::isSynthetic() {
        return this->accessFlags & ACC_SYNTHETIC;
    }
}
