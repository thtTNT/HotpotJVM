//
// Created by 屠昊天 on 2022/3/14.
//

#include "Class.h"
#include "Method.h"
#include "Field.h"

namespace heap {

    Class *newClass(ClassFile *classFile) {
        auto clazz = new Class();
        clazz->accessFlags = classFile->AccessFlags();
        clazz->name = classFile->ClassName();
        clazz->superClassName = classFile->SuperClassName();
        clazz->interfaceNames = classFile->InterfaceNames();
        clazz->constantPool = newConstantPool(clazz, classFile->ConstantPool());
        clazz->fields = newFields(clazz, classFile->Fields());
        clazz->methods = newMethods(clazz, classFile->Methods());
        return clazz;
    }

    bool Class::isPublic() {
        return this->accessFlags & ACC_PUBLIC;
    }

    bool Class::isFinal() {
        return this->accessFlags & ACC_FINAL;
    }

    bool Class::isInterface() {
        return this->accessFlags & ACC_INTERFACE;
    }

    bool Class::isAbstract() {
        return this->accessFlags & ACC_ABSTRACT;
    }

    bool Class::isSynthetic() {
        return this->accessFlags & ACC_SYNTHETIC;
    }

    bool Class::isAnnotation() {
        return this->accessFlags & ACC_ANNOTATION;
    }

    bool Class::isEnum() {
        return this->accessFlags & ACC_ENUM;
    }

    bool Class::isAccessibleTo(Class *clazz) {
        return this->isPublic() || this->getPackageName() == clazz->getPackageName();
    }

    std::string Class::getPackageName() {
        auto index = this->name.find_last_of("/");
        if (index == std::string::npos) {
            return "";
        }
        auto packageName = this->name.substr(0, index);
        return packageName;
    }

    bool Class::isSubClassOf(Class *clazz) {
        if (this->superClass == clazz) {
            return true;
        } else {
            if (this->superClass == nullptr) {
                return false;
            }
            return this->superClass->isSubClassOf(clazz);
        }

    }


    Object *Class::newObject() {
        return new Object(this);
    }

    bool Class::isAssignableForm(Class *pClass) {
        if (this == pClass) {
            return true;
        }
        if (!this->isInterface()) {
            return pClass->isSubClassOf(this);
        } else {
            return pClass->isImplements(this);
        }
    }

    bool Class::isImplements(Class *interface) {
        for (auto clazz = interface; clazz != nullptr; clazz = interface->superClass) {
            for (auto interface1: clazz->interfaceClass) {
                if (interface == interface1 || interface1->isSubInterfaceOf(interface)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Class::isSubInterfaceOf(Class *interface) {
        for (auto superInterface: interface->interfaceClass) {
            if (superInterface == interface || superInterface->isSubInterfaceOf(interface)) {
                return true;
            }
        }
        return false;
    }

    Method *Class::getMainMethod() {
        return this->getStaticMethod("main", "([Ljava/lang/String;)V");
    }

    Method *Class::getStaticMethod(std::string methodName, std::string descriptor) {
        for (auto method: this->methods) {
            if (method->isStatic() && method->name == methodName && method->descriptor == descriptor) {
                return method;
            }
        }
        return nullptr;
    }

}
