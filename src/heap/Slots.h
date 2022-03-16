//
// Created by 屠昊天 on 2022/3/15.
//

#ifndef HOTPOTJVM_HEAP_SLOTS_H
#define HOTPOTJVM_HEAP_SLOTS_H

#include "Object.h"
#include <vector>

namespace heap {
    union Slot {
        int intValue = 0;
        float floatValue;
        Object *ref;
    };

    class Slots {
        std::vector<Slot> slots;

    public:
        Slots(int slotCount);

        void setInt(unsigned index, int value);

        int getInt(unsigned index);

        void setFloat(unsigned index, float value);

        float getFloat(unsigned index);

        void setLong(unsigned index, long value);

        long getLong(unsigned index);

        void setDouble(unsigned index, double value);

        double getDouble(unsigned index);

        void setRef(unsigned index, Object *object);

        Object *getRef(unsigned index);
    };
}


#endif //HOTPOTJVM_HEAP_SLOTS_H
