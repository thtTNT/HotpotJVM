//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_CLASS_H
#define HOTPOTJVM_CLASS_H

#include <string>
#include <vector>
#include "../classfile/ConstantPool.h"
#include "../classfile/ClassFile.h"
#include "ConstantPool.h"
#include "ClassLoader.h"
#include "Slots.h"

const unsigned short ACC_PUBLIC = 0x0001;
const unsigned short ACC_PRIVATE = 0x0002;
const unsigned short ACC_PROTECTED = 0x0004;
const unsigned short ACC_STATIC = 0x0008;
const unsigned short ACC_FINAL = 0x0010;
const unsigned short ACC_SUPER = 0x0020;
const unsigned short ACC_SYNCHRONIZED = 0x0020;
const unsigned short ACC_VOLATILE = 0x0040;
const unsigned short ACC_BRIDGE = 0x0040;
const unsigned short ACC_TRANSIENT = 0x0080;
const unsigned short ACC_VARARGS = 0x0080;
const unsigned short ACC_NATIVE = 0x0100;
const unsigned short ACC_INTERFACE = 0x0200;
const unsigned short ACC_ABSTRACT = 0x0400;
const unsigned short ACC_STRICT = 0x0800;
const unsigned short ACC_SYNTHETIC = 0x1000;
const unsigned short ACC_ANNOTATION = 0x2000;
const unsigned short ACC_ENUM = 0x4000;


using classFile::ClassFile;

namespace heap {
    class Field;

    class Method;

    class Class {
    public:
        unsigned short accessFlags;
        std::string name;
        std::string superClassName;
        std::vector<std::string> interfaceNames;
        heap::ConstantPool *constantPool;
        std::vector<Field *> fields;
        std::vector<Method *> methods;
        ClassLoader *loader;
        Class *superClass;
        std::vector<Class *> interfaceClass;
        unsigned instanceSlotCount;
        unsigned staticSlotCount;
        Slots *staticVars;
        bool initStarted = false;

        Class();

        Class(unsigned short accessFlags, const std::string &name, ClassLoader *loader, Class *superClass,
              const std::vector<Class *> &interfaceClass, bool initStarted);

        bool isPublic();

        bool isFinal();

        bool isSuper();

        bool isInterface();

        bool isAbstract();

        bool isSynthetic();

        bool isAnnotation();

        bool isEnum();

        bool isAccessibleTo(Class *clazz);

        bool isSubClassOf(Class *clazz);

        bool isSuperClassOf(Class *clazz);

        bool isImplements(Class *interface);

        std::string getPackageName();

        Object *newObject();

        Object *newArray(unsigned count);

        bool isAssignableForm(Class *pClass);

        bool isSubInterfaceOf(Class *interface);

        bool isArray();

        Method *getStaticMethod(std::string methodName, std::string descriptor);

        Method *getMainMethod();

        bool isInitStarted() const;

        void startInit();

        Method *getClinitMethod();

        Class *getArrayClass();

        Class *getComponentClass();

        bool isJlObject();

        bool isJLCloneable();

        bool JIoSerializable();

        bool isSuperInterfaceOf(Class *pClass);
    };

    Class *newClass(ClassFile *classFile);

    std::string descriptorTypeToClassName(std::string descriptorType);
}


#endif //HOTPOTJVM_CLASS_H
