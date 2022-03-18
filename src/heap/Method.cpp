//
// Created by 屠昊天 on 2022/3/14.
//

#include "Method.h"
#include "../utils/ByteReader.h"
#include "../exception/ClassNotSupportException.h"

namespace heap {
    std::vector<Method *> newMethods(Class *clazz, std::vector<classFile::MemberInfo *> classFileMethods) {
        auto methods = std::vector<Method *>(classFileMethods.size());
        for (int i = 0; i < classFileMethods.size(); i++) {
            methods[i] = new Method(clazz, classFileMethods[i]);
        }
        return methods;
    }

    std::string parseField(ByteReader &reader) {
        switch (reader.readUint8()) {
            case 'B':
                return "B";
            case 'C':
                return "C";
            case 'D':
                return "D";
            case 'F':
                return "F";
            case 'I':
                return "I";
            case 'J':
                return "J";
            case 'S':
                return "S";
            case 'Z':
                return "Z";
            case 'L': {
                int nextSemicolon = reader.getStr().find(";", reader.getIndex());
                if (nextSemicolon == std::string::npos) {
                    throw ClassNotSupportException();
                } else {
                    auto descriptor = reader.getStr().substr(reader.getIndex() - 1,
                                                             nextSemicolon - reader.getIndex() + 1);
                    reader.setIndex(nextSemicolon + 1);
                    return descriptor;
                }
            }
            case '[': {
                return "[" + parseField(reader);
            }
            default:
                reader.rollback(1);
                return "";
        }
    }

    MethodDescriptor parseDescriptor(std::string descriptor) {
        auto reader = ByteReader(descriptor);
        auto descriptorInstance = MethodDescriptor{};

        // Check Start Params
        if (reader.readUint8() != '(') {
            throw ClassNotSupportException();
        }

        // Parse param types
        while (true) {
            auto fieldDescriptor = parseField(reader);
            if (fieldDescriptor != "") {
                descriptorInstance.parameterTypes.push_back(fieldDescriptor);
            } else {
                break;
            }
        }

        // Check End Params
        if (reader.readUint8() != ')') {
            throw ClassNotSupportException();
        }

        // Read return type
        if (reader.readUint8() == 'V') {
            descriptorInstance.returnType = "V";
        } else {
            reader.rollback(1);
            auto fieldDescriptor = parseField(reader);
            if (fieldDescriptor == "") {
                throw ClassNotSupportException();
            }
            descriptorInstance.returnType = fieldDescriptor;
        }

        // check if is ended
        if (!reader.isEnd()) {
            throw ClassNotSupportException();
        }

        return descriptorInstance;
    }


    Method::Method(Class *clazz, classFile::MemberInfo *classFileMethod) {
        this->clazz = clazz;
        this->copyMemberInfo(classFileMethod);
        this->copyAttribute(classFileMethod);
        this->calculateArgSlotCount();
    }

    void Method::copyAttribute(classFile::MemberInfo *classFileMethod) {
        auto codeAttribute = classFileMethod->getCodeAttribute();
        if (codeAttribute != nullptr) {
            this->maxStack = codeAttribute->maxStack;
            this->maxLocals = codeAttribute->maxLocals;
            this->code = codeAttribute->code;
        }
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

    unsigned Method::getArgSlotCount() {
        return this->argSlotCount;
    }

    void Method::calculateArgSlotCount() {
        auto methodDescriptor = parseDescriptor(this->descriptor);
        auto count = 0;
        for (auto fieldDescriptor: methodDescriptor.parameterTypes) {
            count++;
            if (fieldDescriptor == "J" || fieldDescriptor == "D") {
                count++;
            }
        }
        if (!this->isStatic()) {
            count++;
        }
        this->argSlotCount = count;
    }
}
