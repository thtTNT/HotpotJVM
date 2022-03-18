//
// Created by 屠昊天 on 2022/3/14.
//

#include "Class.h"
#include "Method.h"
#include "Field.h"
#include "../exception/RuntimeException.h"

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

    bool Class::isSuper() {
        return this->accessFlags & ACC_SUPER;
    }

    bool Class::isSuperClassOf(Class *other) {
        return other->isSubClassOf(this);
    }

    bool Class::isArray() {
        return this->name[0] == '[';
    }

    Object *Class::newArray(unsigned count) {
        if (!this->isArray()) {
            throw RuntimeException("Not array class: " + this->name);
        }

        if (this->name == "[Z") {
            return new Object(this, DATA_TYPE_BYTE, count);
        } else if (this->name == "[B") {
            return new Object(this, DATA_TYPE_BYTE, count);
        } else if (this->name == "[C") {
            return new Object(this, DATA_TYPE_CHAR, count);
        } else if (this->name == "[S") {
            return new Object(this, DATA_TYPE_SHORT, count);
        } else if (this->name == "[I") {
            return new Object(this, DATA_TYPE_INT, count);
        } else if (this->name == "[J") {
            return new Object(this, DATA_TYPE_LONG, count);
        } else if (this->name == "[F") {
            return new Object(this, DATA_TYPE_FLOAT, count);
        } else if (this->name == "[D") {
            return new Object(this, DATA_TYPE_DOUBLE, count);
        } else {
            return new Object(this, DATA_TYPE_OBJECT, count);
        }
    }

    Class::Class(unsigned short accessFlags, const std::string &name, ClassLoader *loader, Class *superClass,
                 const std::vector<Class *> &interfaceClass) : accessFlags(accessFlags), name(name), loader(loader),
                                                               superClass(superClass), interfaceClass(interfaceClass) {}

    bool Class::isInitStarted() const {
        return initStarted;
    }

    void Class::startInit() {
        this->initStarted = true;
    }

    Method *Class::getClinitMethod() {
        return nullptr;
    }

    Class::Class() {}

}
