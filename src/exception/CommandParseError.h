//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_COMMANDPARSEERROR_H
#define HOTPOTJVM_COMMANDPARSEERROR_H

#include<exception>
#include<string>

class CommandParseError : std::exception {
public:
    explicit CommandParseError(std::string message);
    std::string message;
};

#endif //HOTPOTJVM_COMMANDPARSEERROR_H
