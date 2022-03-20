//
// Created by 屠昊天 on 2022/3/14.
//

#include "Class.h"
#include "Method.h"
#include "Field.h"
#include "../exception/RuntimeException.h"
#include "ClassLoader.h"

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

    std::string descriptorTypeToClassName(std::string descriptorType) {
        if (descriptorType[0] == '[') {
            return descriptorType;
        } else if (descriptorType[0] == 'L') {
            return descriptorType.substr(1, descriptorType.length() - 2);
        } else if (descriptorType == "V") {
            return "void";
        } else if (descriptorType == "Z") {
            return "boolean";
        } else if (descriptorType == "B") {
            return "byte";
        } else if (descriptorType == "S") {
            return "short";
        } else if (descriptorType == "I") {
            return "int";
        } else if (descriptorType == "L") {
            return "long";
        } else if (descriptorType == "C") {
            return "char";
        } else if (descriptorType == "F") {
            return "float";
        } else if (descriptorType == "D") {
            return "double";
        } else {
            throw RuntimeException("Invalid descriptor: " + descriptorType);
        }
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

    bool Class::isAssignableForm(Class *otherClass) {
        if (otherClass == this) {
            return true;
        }
        if (!otherClass->isArray()) {
            if (!otherClass->isInterface()) {
                if (!this->isInterface()) {
                    return otherClass->isSubClassOf(this);
                } else {
                    return otherClass->isImplements(this);
                }
            } else {
                if (!this->isInterface()) {
                    return this->isJlObject();
                } else {
                    return this->isSuperInterfaceOf(otherClass);
                }
            }
        } else {
            if (!this->isArray()) {
                if (!this->isInterface()) {
                    return this->isJlObject();
                } else {
                    return this->isJLCloneable() || this->JIoSerializable();
                }
            } else {
                auto otherClassComponent = otherClass->getComponentClass();
                auto thisClassComponent = this->getComponentClass();
                return otherClassComponent == thisClassComponent || otherClass->isAssignableForm(this);
            }
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
                 const std::vector<Class *> &interfaceClass, bool initStarted) : accessFlags(accessFlags), name(name),
                                                                                 loader(loader),
                                                                                 superClass(superClass),
                                                                                 interfaceClass(interfaceClass),
                                                                                 initStarted(initStarted) {
    }

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


    std::string getArrayClassName(std::string className) {
        if (className[0] == '[') {
            return "[" + className;
        }
        if (className == "void") {
            return "[V";
        } else if (className == "boolean") {
            return "[Z";
        } else if (className == "byte") {
            return "[B";
        } else if (className == "short") {
            return "[S";
        } else if (className == "int") {
            return "[I";
        } else if (className == "long") {
            return "[L";
        } else if (className == "char") {
            return "[C";
        } else if (className == "float") {
            return "[F";
        } else if (className == "double") {
            return "[D";
        } else {
            return "[L" + className + ";";
        }
    }

    Class *Class::getArrayClass() {
        auto arrayClassName = getArrayClassName(this->name);
        return this->loader->loadClass(arrayClassName);
    }

    Class *Class::getComponentClass() {
        if (this->name[0] == '[') {
            auto componentTypeDescriptor = this->name.substr(1, this->name.length() - 1);
            auto className = descriptorTypeToClassName(componentTypeDescriptor);
            return this->loader->loadClass(className);
        } else {
            throw RuntimeException("Not array: " + this->name);
        }
    }

    bool Class::isJlObject() {
        return this->name == "java/lang/Object";
    }

    bool Class::isJLCloneable() {
        return this->name == "java/lang/Cloneable";
    }

    bool Class::JIoSerializable() {
        return this->name == "java/io/Serializable";
    }

    bool Class::isSuperInterfaceOf(Class *otherClass) {
        return otherClass->isSubInterfaceOf(this);
    }

    Field * Class::getField(std::string fieldName, std::string descriptor, bool isStatic) {
        for (auto clazz = this; clazz != nullptr; clazz = clazz->superClass) {
            for (auto field: clazz->fields) {
                if (field->isStatic() == isStatic && field->name == fieldName && field->descriptor == descriptor) {
                    return field;
                }
            }
        }
        return nullptr;
    }

}
