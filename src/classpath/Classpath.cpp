//
// Created by 屠昊天 on 2022/3/8.
//

#include "Classpath.h"
#include "../utils/Utils.h"

Classpath Classpath::parse(const std::string& jrePath, const std::string& userClasspath) {
    auto classpath = Classpath();
    classpath.bootClasspath = createEntry(jrePath + "lib/*");
    classpath.extClasspath = createEntry(jrePath + "lib/ext/*");
    classpath.userClasspath = createEntry(userClasspath);
    return classpath;
}

std::string Classpath::string() {
    this->bootClasspath->string();
    this->extClasspath->string();
    this->userClasspath->string();
}

char *Classpath::readClass(const std::string& className) {
    auto bs = this->bootClasspath->readClass(className);
    if (bs != nullptr){
        return bs;
    }
    bs = this->extClasspath->readClass(className);
    if (bs != nullptr){
        return bs;
    }
    bs = this->userClasspath->readClass(className);
    if (bs != nullptr){
        return bs;
    }
}
