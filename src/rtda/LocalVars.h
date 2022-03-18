//
// Created by 屠昊天 on 2022/3/12.
//

#ifndef HOTPOTJVM_LOCALVARS_H
#define HOTPOTJVM_LOCALVARS_H

#include<vector>
#include "Slot.h"

class LocalVars {
public:
    std::vector<Slot> slots;

    void setSlot(unsigned index, Slot slot);

    Slot getSlot(unsigned index);

    void setInt(unsigned index, int value);

    int getInt(unsigned index);

    void setFloat(unsigned index, float value);

    float getFloat(unsigned index);

    void setLong(unsigned index, long value);

    long getLong(unsigned index);

    void setDouble(unsigned index, double value);

    double getDouble(unsigned index);

    void setObject(unsigned index, heap::Object *object);

    heap::Object *getObject(unsigned index);
};

LocalVars *newLocalVars(unsigned int maxLocals);


#endif //HOTPOTJVM_LOCALVARS_H
