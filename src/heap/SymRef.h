//
// Created by 屠昊天 on 2022/3/15.
//

#ifndef HOTPOTJVM_SYMREF_H
#define HOTPOTJVM_SYMREF_H

#include "../classfile/constant/ConstantClassInfo.h"
#include "../classfile/constant/ConstantMemberRefInfo.h"

namespace heap {
    class Class;

    class Method;

    class Field;

    class ConstantPool;

    class SymRef {
    public:
        ConstantPool *constantPool;
        std::string className;
        Class *clazz;

        Class *resolvedClass();

        void resolveClassRef();
    };

    class ClassRef : public SymRef {
    };

    ClassRef *newClassRef(ConstantPool *constantPool, classFile::ConstantClassInfo classInfo);

    class MemberRef : public SymRef {
        std::string name;
        std::string description;
    public:
        void copyMemberRefInfo(classFile::ConstantMemberRefInfo refInfo);

        const std::string &getName() const;

        const std::string &getDescription() const;
    };

    class FieldRef : public MemberRef {
    private:
        Field *field;

        Field *lookupField(Class *destClazz, std::string name, std::string descriptor);

        void resolveFieldRef();

    public:
        Field *resolvedField();
    };

    FieldRef *newFieldRef(ConstantPool *constantPool, classFile::ConstantFieldRefInfo refInfo);

    class MethodRef : public MemberRef {
        Method *method;
    };

    MemberRef *newMethodRef(ConstantPool *constantPool, classFile::ConstantMethodRefInfo refInfo);

    class InterfaceMethodRef : public MemberRef {
        Method *method;
    };

    InterfaceMethodRef *
    newInterfaceMethodRef(ConstantPool *constantPool, classFile::ConstantInterfaceMethodRefInfo refInfo);
}


#endif //HOTPOTJVM_SYMREF_H
