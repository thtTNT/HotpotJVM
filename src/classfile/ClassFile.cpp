//
// Created by 屠昊天 on 2022/3/8.
//

#include "ClassFile.h"
#include "MemberInfo.h"

using namespace classFile;

void ClassFile::read(ClassReader *reader) {
    this->magic = reader->readUint32();
    this->minorVersion = reader->readUint16();
    this->majorVersion = reader->readUint16();
    this->constantPool = readConstantPool(reader);
    this->accessFlags = reader->readUint16();
    this->thisClass = reader->readUint16();
    this->superClass = reader->readUint16();
    this->interfaces = reader->readUint16s();
    this->fields = readMembers(reader, constantPool);
    this->methods = readMembers(reader, constantPool);
    this->attributeInfo = readAttributes(reader, constantPool);
}

unsigned short ClassFile::MinorVersion() const {
    return this->minorVersion;
}

unsigned short ClassFile::MajorVersion() const {
    return this->majorVersion;
}

std::vector<MemberInfo *> ClassFile::Methods() {
    return this->methods;
}

ConstantPool *ClassFile::ConstantPool() {
    return this->constantPool;
}

unsigned short ClassFile::AccessFlags() {
    return this->accessFlags;
}

std::vector<MemberInfo *> ClassFile::Fields() {
    return this->fields;
}

std::string ClassFile::ClassName() {
    return this->constantPool->getClassName(this->thisClass);
}

std::string ClassFile::SuperClassName() {
    if (this->superClass > 0) {
        return this->constantPool->getClassName(this->superClass);
    } else {
        return "";
    }
}

std::vector<std::string> ClassFile::InterfaceNames() {
    auto interfaceNames = std::vector<std::string>(this->interfaces.size());
    for (int i = 0; i < 0; i++) {
        interfaceNames[i] = this->constantPool->getUTF8(this->interfaces[i]);
    }
    return interfaceNames;
}

ClassFile *ClassFile::parse(std::string *bs) {
    auto reader = new ClassReader(bs);
    auto classFile = new ClassFile();
    classFile->read(reader);
    delete reader;
    return classFile;
}
