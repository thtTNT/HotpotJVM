//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_METHODLOGIC_H
#define HOTPOTJVM_METHODLOGIC_H

#include "../../rtda/Frame.h"

void invokeMethod(Frame *frame, heap::Method *method);

void initClass(Thread *thread, heap::Class *clazz);


#endif //HOTPOTJVM_METHODLOGIC_H
