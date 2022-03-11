//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_CLASSFILE_H
#define HOTPOTJVM_CLASSFILE_H


#include <vector>
#include <string>
#include "ConstantPool.h"
#include "MemberInfo.h"
#include "AttributeInfo.h"
#include "ClassReader.h"

class ClassFile {
private:
    unsigned int magic;
    unsigned short minorVersion;
    unsigned short majorVersion;
    ConstantPool *constantPool;
    unsigned short accessFlags;
    unsigned short thisClass;
    unsigned short superClass;
    std::vector<unsigned short> interfaces;
    std::vector<MemberInfo *> fields;
    std::vector<MemberInfo *> methods;
    std::vector<AttributeInfo *> attributeInfo;

public:
    static ClassFile *parse(std::string *bs);

    void read(ClassReader *reader);

    unsigned short MinorVersion() const;

    unsigned short MajorVersion() const;

    ConstantPool ConstantPool();

    unsigned short AccessFlags();

    std::vector<MemberInfo> Fields();

    std::vector<MemberInfo> Methods();

    std::string ClassName();

    std::string SuperClassName();

    std::vector<std::string> InterfaceNames();

};


#endif //HOTPOTJVM_CLASSFILE_H
