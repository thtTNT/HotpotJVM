//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_OBJECT_H
#define HOTPOTJVM_OBJECT_H


namespace heap {
    class Class;

    class Slots;

    class Object {
    private:
        Class *clazz;
        Slots *fields;
    public:
        Object(Class *clazz);

        Class *getClass() const;

        Slots *getFields() const;

        bool isInstanceOf(Class *clazz);
    };
}


#endif //HOTPOTJVM_OBJECT_H
