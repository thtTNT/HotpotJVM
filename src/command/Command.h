//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_COMMAND_H
#define HOTPOTJVM_COMMAND_H

#include <string>
#include <vector>
#include <iostream>
#include "../exception/CommandParseError.h"


struct JVMStartInfo {
    std::string className;
    std::string classpath;
    std::string Xjre;
    std::vector<std::string> args;
};

namespace Args {
    class CmdLine;
}

void executeCommand(int argc, char *argv[]);

JVMStartInfo parseCommand(int argc, char *argv[]);

void printCommand(const JVMStartInfo &info);

void executeCommand(const JVMStartInfo &info);

#endif //HOTPOTJVM_COMMAND_H