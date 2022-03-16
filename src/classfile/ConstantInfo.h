//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTINFO_H
#define HOTPOTJVM_CONSTANTINFO_H

#include "ClassReader.h"
#include "ConstantPool.h"

#define CONSTANT_CLASS 7
#define CONSTANT_FIELD_REF 9
#define CONSTANT_METHOD_REF 10
#define CONSTANT_INTERFACE_METHOD_REF 11
#define CONSTANT_STRING 8
#define CONSTANT_INTEGER 3
#define CONSTANT_FLOAT 4
#define CONSTANT_LONG 5
#define CONSTANT_DOUBLE 6
#define CONSTANT_NAME_AND_TYPE 12
#define CONSTANT_UTF8 1
#define CONSTANT_METHOD_HANDLE 15
#define CONSTANT_METHOD_TYPE 16
#define CONSTANT_INVOKE_DYNAMIC 18


namespace classFile {

    class ConstantInfo {
    public:
        unsigned char type;

        explicit ConstantInfo(unsigned char type);

        virtual void readInfo(ClassReader *reader) = 0;
    };

    ConstantInfo *readConstantInfo(ClassReader *reader, ConstantPool *constantPool);

}

#endif //HOTPOTJVM_CONSTANTINFO_H