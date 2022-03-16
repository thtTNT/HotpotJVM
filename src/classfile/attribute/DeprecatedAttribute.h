//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_DEPRECATEDATTRIBUTE_H
#define HOTPOTJVM_DEPRECATEDATTRIBUTE_H


#include "../AttributeInfo.h"

namespace classFile {
    class DeprecatedAttribute : public AttributeInfo {
    public:
        DeprecatedAttribute();

        void readInfo(ClassReader *reader) override;
    };

}

#endif //HOTPOTJVM_DEPRECATEDATTRIBUTE_H
