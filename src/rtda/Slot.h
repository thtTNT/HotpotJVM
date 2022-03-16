//
// Created by 屠昊天 on 2022/3/12.
//

#include "../heap/Object.h"

#ifndef HOTPOTJVM_SLOT_H
#define HOTPOTJVM_SLOT_H


class Slot {
public:
    int num;
    heap::Object *ref;
};


#endif //HOTPOTJVM_SLOT_H
