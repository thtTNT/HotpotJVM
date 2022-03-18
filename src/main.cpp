#include <iostream>
#include "command/Command.h"

int main(int argc, char *argv[]) {
    try {
//        JVMStartInfo commandInfo = parseCommand(argc, argv);
//        printCommand(commandInfo);
//        executeCommand(commandInfo);
        executeCommand(argc, argv);
    } catch (CommandParseError &error) {
        std::cout << "CommandParseError: " << error.message << std::endl;
    }
    return 0;
}
