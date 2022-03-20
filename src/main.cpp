#include <iostream>
#include "command/Command.h"
#include "exception/CommandParseError.h"

int main(int argc, char *argv[]) {
    try {
        executeCommand(argc, argv);
    } catch (CommandParseError &error) {
        std::cout << "CommandParseError: " << error.message << std::endl;
    }
    return 0;
}
