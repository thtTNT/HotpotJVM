//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_CLASSMEMBER_H
#define HOTPOTJVM_CLASSMEMBER_H

#include <string>
#include "Class.h"

namespace heap {
    class ClassMember {
    public:
        unsigned short accessFlags;
        std::string name;
        std::string descriptor;
        Class *clazz;

        Class *getClass() const;

        ConstantPool *getConstantPool();

        void copyMemberInfo(classFile::MemberInfo *memberInfo);
    };
}


#endif //HOTPOTJVM_CLASSMEMBER_H
