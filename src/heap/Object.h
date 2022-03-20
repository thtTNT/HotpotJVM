//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_OBJECT_H
#define HOTPOTJVM_OBJECT_H

#include <vector>

const int DATA_TYPE_FIELD = 1;
const int DATA_TYPE_BYTE = 2;
const int DATA_TYPE_SHORT = 3;
const int DATA_TYPE_INT = 4;
const int DATA_TYPE_LONG = 5;
const int DATA_TYPE_CHAR = 6;
const int DATA_TYPE_FLOAT = 7;
const int DATA_TYPE_DOUBLE = 8;
const int DATA_TYPE_OBJECT = 9;


namespace heap {
    class Class;

    class Slots;

    class Object {
    private:
        Class *clazz;

        int type;
        union {
            Slots *fields;
            std::vector<char> *bytes;
            std::vector<short> *shorts;
            std::vector<int> *ints;
            std::vector<long> *longs;
            std::vector<unsigned short> *chars;
            std::vector<float> *floats;
            std::vector<double> *doubles;
            std::vector<Object *> *refs;
        };


    public:
        // Normal Object
        Object(Class *clazz);

        // Array
        Object(Class *clazz, int type, unsigned count);

        Class *getClass() const;

        Slots *getFields() const;

        bool isInstanceOf(Class *clazz);

        int arrayLength();

        std::vector<char> *getBytes() const;

        std::vector<short> *getShorts() const;

        std::vector<int> *getInts() const;

        std::vector<long> *getLongs() const;

        std::vector<unsigned short> *getChars() const;

        std::vector<float> *getFloats() const;

        std::vector<double> *getDoubles() const;

        std::vector<Object *> *getRefs() const;

        void setRefVar(std::string name, std::string descriptor, Object *ref);

        heap::Object *getRefVar(std::string name, std::string descriptor);
    };
}


#endif //HOTPOTJVM_OBJECT_H
