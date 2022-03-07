//
// Created by 屠昊天 on 2022/3/8.
//
#include "Command.h"

CommandInfo parseCommand(int argc, char *argv[]) {
    CommandInfo info;
    if (argc == 1) {
        info.helpFlag = true;
        info.versionFlag = false;
        return info;
    }
    if (strcmp(argv[1], "-help") == 0) {
        info.helpFlag = true;
        info.versionFlag = false;
        return info;
    }
    if (strcmp(argv[1], "-version") == 0) {
        info.helpFlag = false;
        info.versionFlag = true;
        return info;
    }
    int index = 1;
    while (index < argc) {
        // Parse classpath
        if (strcmp(argv[index], "-cp") == 0 || strcmp(argv[index], "-classpath") == 0) {
            if (argc == index + 1) {
                throw CommandParseError{};
            }
            info.classpath = argv[++index];
            index++;
            continue;
        }

        // Parse class name
        info.className = argv[index];
        index++;

        // Parse args
        while (index < argc) {
            info.args.emplace_back(argv[index]);
            index++;
        }
    }
    return info;
}

void printCommand(const CommandInfo &info) {
    std::cout << "helpFlag: " << info.helpFlag << std::endl;
    std::cout << "versionFlag: " << info.versionFlag << std::endl;
    std::cout << "classpath: " << info.classpath << std::endl;
    std::cout << "className: " << info.className << std::endl;
    // Print args
    std::cout << "args: ";
    for (const auto &arg : info.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
}

void executeCommand(const CommandInfo &info) {
    if (info.helpFlag) {
        std::cout << "Usage: HotpotJVM [-options] class [args...]\n"
                     "      -help list all command of Hotpot JVM\n"
                     "      -version show the version of Hotpot JVM\n"
                     "      -classpath[cp] set the classpath";
        return;
    }
    if (info.versionFlag) {
        std::cout << "HotpotJVM version 0.0.1";
        return;
    }
}

