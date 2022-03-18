//
// Created by 屠昊天 on 2022/3/14.
//

#include "ClassLoader.h"
#include "Class.h"
#include "Field.h"
#include "../exception/ClassNotSupportException.h"

heap::Class *heap::ClassLoader::loadClass(std::string name) {
    if (classMap[name] != nullptr) {
        return classMap[name];
    }

    if (name[0] == '[') {
        return this->loadArrayClass(name);
    } else {
        return this->loadNonArrayClass(name);
    }
}

heap::ClassLoader::ClassLoader(Classpath *classpath) : classpath(classpath) {
}

heap::Class *heap::ClassLoader::loadNonArrayClass(std::string name) {
    auto data = this->readClass(name);
    auto clazz = this->defineClass(data);
    link(clazz);
    return clazz;
}

std::string heap::ClassLoader::readClass(std::string name) {
    auto data = this->classpath->readClass(name);
    return *data;
}

heap::Class *heap::ClassLoader::defineClass(std::string data) {
    auto clazz = parseClass(data);
    clazz->loader = this;
    resolveSuperClass(clazz);
    resolveInterfaces(clazz);
    this->classMap[clazz->name] = clazz;
    return clazz;
}

heap::Class *heap::ClassLoader::parseClass(std::string data) {
    auto classFile = classFile::ClassFile::parse(&data);
    return newClass(classFile);
}

void heap::ClassLoader::resolveSuperClass(heap::Class *clazz) {
    if (clazz->name != "java/lang/Object") {
        clazz->superClass = clazz->loader->loadClass(clazz->superClassName);
    }
}

void heap::ClassLoader::resolveInterfaces(Class *clazz) {
    auto count = clazz->interfaceNames.size();
    if (count > 0) {
        clazz->interfaceClass = std::vector<Class *>(count);
        for (int i = 0; i < count; i++) {
            clazz->interfaceClass[i] = clazz->loader->loadClass(clazz->interfaceNames[i]);
        }
    }
}

void heap::ClassLoader::link(Class *clazz) {
    prepare(clazz);
}

void heap::ClassLoader::prepare(Class *clazz) {
    this->calculateInstanceFieldsSlotIds(clazz);
    this->calculateStaticFieldSlotIds(clazz);
    this->allocAndInitStaticVars(clazz);
}

void heap::ClassLoader::calculateInstanceFieldsSlotIds(Class *clazz) {
    unsigned int slotId = 0;
    if (clazz->superClass != nullptr) {
        slotId = clazz->superClass->instanceSlotCount;
    }

    for (auto field: clazz->fields) {
        if (!field->isStatic()) {
            field->slotId = slotId;
            slotId++;
            if (field->isLongOrDouble()) {
                field++;
            }
        }
    }
    clazz->instanceSlotCount = slotId;
}

void heap::ClassLoader::calculateStaticFieldSlotIds(Class *clazz) {
    unsigned int slotId = 0;
    for (auto field: clazz->fields) {
        if (field->isStatic()) {
            field->slotId = slotId;
            slotId++;
            if (field->isLongOrDouble()) {
                slotId++;
            }
        }
    }
    clazz->staticSlotCount = slotId;
}

void heap::ClassLoader::allocAndInitStaticVars(Class *clazz) {
    clazz->staticVars = new Slots(clazz->staticSlotCount);
    for (auto field: clazz->fields) {
        if (field->isStatic() || field->isFinal()) {
            initStaticFinalVar(clazz, field);
        }
    }
}

void heap::ClassLoader::initStaticFinalVar(Class *clazz, Field *field) {
    auto vars = clazz->staticVars;
    auto constantPool = clazz->constantPool;
    auto constantValueIndex = field->getConstValueIndex();
    auto slotId = field->slotId;
    if (constantValueIndex > 0) {
        if (field->descriptor == "Z" || field->descriptor == "B" || field->descriptor == "C" ||
            field->descriptor == "S" || field->descriptor == "I") {
            auto value = constantPool->getConstant(constantValueIndex).intValue;
            vars->setInt(slotId, value);
        } else if (field->descriptor == "J") {
            auto value = constantPool->getConstant(constantValueIndex).longValue;
            vars->setFloat(constantValueIndex, value);
        } else if (field->descriptor == "F") {
            auto value = constantPool->getConstant(constantValueIndex).floatValue;
            vars->setFloat(constantValueIndex, value);
        } else if (field->descriptor == "D") {
            auto value = constantPool->getConstant(constantValueIndex).doubleValue;
            vars->setDouble(constantValueIndex, value);
        } else if (field->descriptor == "Ljava/lang/String") {
            // TODO
            throw ClassNotSupportException();
        }
    }
}

heap::Class *heap::ClassLoader::loadArrayClass(std::string name) {
    auto clazz = new Class();
}

heap::ClassLoader *heap::newClassLoader(Classpath *classpath) {
    return new ClassLoader(classpath);
}
