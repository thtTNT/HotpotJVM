//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_HEAP_CONSTANTPOOL_H
#define HOTPOTJVM_HEAP_CONSTANTPOOL_H

#include "../classfile/ConstantPool.h"
#include "SymRef.h"
#include <vector>

namespace heap {

    enum ConstantType {
        INT,
        FLOAT,
        LONG,
        DOUBLE,
        STRING,
        CLASS,
        FIELD_REF,
        METHOD_REF,
        INTERFACE_METHOD_REF
    };

    class Class;

    class Constant {
    public:
        ConstantType type;
        union {
            int intValue;
            float floatValue;
            long longValue;
            double doubleValue;
            SymRef *symRef;
        };
        std::string stringValue;
    };

    class ConstantPool {
    public:
        Class *clazz;
        std::vector<Constant> consts;

        ConstantPool(Class *clazz, std::vector<Constant> consts);

        Constant getConstant(unsigned index);
    };

    ConstantPool *newConstantPool(Class *clazz, classFile::ConstantPool *classFileConstantPool);
}

#endif //HOTPOTJVM_HEAP_CONSTANTPOOL_H
