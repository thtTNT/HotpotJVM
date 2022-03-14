//
// Created by 屠昊天 on 2022/3/8.
//

#include "ClassFile.h"
#include "MemberInfo.h"

ClassFile *ClassFile::parse(std::string *bs) {
    auto reader = new ClassReader(bs);
    auto classFile = new ClassFile();
    classFile->read(reader);
    delete reader;
    return classFile;
}

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
