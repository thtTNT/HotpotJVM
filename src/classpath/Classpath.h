//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_CLASSPATH_H
#define HOTPOTJVM_CLASSPATH_H


#include "entry.h"

class Classpath {
private:
    Entry *bootClasspath;
    Entry *extClasspath;
    Entry *userClasspath;
public:
    static Classpath parse(const std::string &jrePath, const std::string &userClasspath);

    void string();

    std::string *readClass(const std::string &className);
};


#endif //HOTPOTJVM_CLASSPATH_H
