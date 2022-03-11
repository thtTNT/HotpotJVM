#include <iostream>
#include "command/Command.h"

int main(int argc, char *argv[]) {
    try {
        CommandInfo commandInfo = parseCommand(argc, argv);
        printCommand(commandInfo);
        executeCommand(commandInfo);
    } catch (CommandParseError &error) {
        std::cout << "CommandParseError: " << error.message << std::endl;
    }
    return 0;
}
