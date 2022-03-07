//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_COMMAND_H
#define HOTPOTJVM_COMMAND_H

#endif //HOTPOTJVM_COMMAND_H

#include <string>
#include <vector>
#include <iostream>
#include "exception/CommandParseError.cpp"

struct CommandInfo {
    bool helpFlag = false;
    bool versionFlag = false;
    std::string className;
    std::string classpath;
    std::vector<std::string> args;
};

CommandInfo parseCommand(int argc, char *argv[]);

void printCommand(const CommandInfo& info);