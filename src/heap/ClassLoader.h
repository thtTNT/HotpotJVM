//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_CLASSLOADER_H
#define HOTPOTJVM_CLASSLOADER_H


#include "../classpath/Classpath.h"
#include <map>
#include <string>
#include "ClassLoader.h"

namespace heap {
    class Field;

    class Class;

    class ClassLoader {
    private:
        Class *loadNonArrayClass(std::string name);

        Class *loadArrayClass(std::string name);

        Class *parseClass(std::string data);

        void resolveSuperClass(Class *clazz);

        void resolveInterfaces(Class *clazz);

        void link(Class *clazz);

        void prepare(Class *clazz);

        void calculateInstanceFieldsSlotIds(Class *clazz);

        void calculateStaticFieldSlotIds(Class *clazz);

        void allocAndInitStaticVars(Class *clazz);

        void initStaticFinalVar(Class *clazz, Field *field);

    public:
        Classpath *classpath;
        std::map<std::string, Class *> classMap;

        ClassLoader(Classpath *classpath);

        Class *loadClass(std::string name);

        std::string readClass(std::string name);

        Class *defineClass(std::string data);
    };

    ClassLoader *newClassLoader(Classpath *classpath);
}


#endif //HOTPOTJVM_CLASSLOADER_H
