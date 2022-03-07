#include <iostream>
#include "Command.h"

int main(int argc,char *argv[]) {
    try {
        CommandInfo commandInfo = parseCommand(argc, argv);
        printCommand(commandInfo);
    } catch (CommandParseError& error){
        std::cout << error.message << std::endl;
    }
    return 0;
}
