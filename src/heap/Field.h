//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_FIELD_H
#define HOTPOTJVM_FIELD_H


#include <vector>
#include "ClassMember.h"

namespace heap {

    class Field : public ClassMember {
    private:
        unsigned constValueIndex;
    public:
        unsigned int slotId;

        bool isPublic();

        bool isPrivate();

        bool isProtected();

        bool isStatic();

        bool isFinal();

        bool isVolatile();

        bool isTransient();

        bool isSynthetic();

        bool isEnum();

        bool isLongOrDouble();

        bool isAccessibleTo(Class *clazz);

        unsigned int getConstValueIndex() const;

        void copyAttribute(classFile::MemberInfo classFileMemberInfo);
    };

    std::vector<Field *> newFields(Class *clazz, std::vector<classFile::MemberInfo *> classFileFields);
}


#endif //HOTPOTJVM_FIELD_H
