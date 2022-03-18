//
// Created by 屠昊天 on 2022/3/19.
//

#ifndef HOTPOTJVM_RUNTIMEEXCEPTION_H
#define HOTPOTJVM_RUNTIMEEXCEPTION_H

#include <exception>
#include <string>

class RuntimeException : public std::exception {
public:
    std::string message;

    RuntimeException(const std::string &message);
};


#endif //HOTPOTJVM_RUNTIMEEXCEPTION_H
