//
// Created by 屠昊天 on 2022/3/8.
//
#include "Command.h"
#include "../utils/Utils.h"
#include "../heap/ClassLoader.h"
#include "../exception/CommandParseError.h"
#include "boost/filesystem/path.hpp"
#include "boost/filesystem/operations.hpp"
#include <args-parser/all.hpp>


void startJVM(const JVMStartInfo &info) {
    auto classpath = Classpath::parse(info.Xjre, info.classpath);
    auto classLoader = heap::newClassLoader(&classpath);
    auto mainClass = classLoader->loadClass(info.className);
    auto mainMethod = mainClass->getMainMethod();
    if (mainMethod != nullptr) {
        interpret(mainMethod, info.args);
    } else {
        std::cout << "Main method not found in class" << std::endl;
    }
}

void executeCommand(int argc, char **argv) {
    Args::CmdLine cmd(argc, argv, Args::CmdLine::HandlePositionalArguments);

    cmd.addArgWithFlagAndName('h', "help", false, false, "Help flag", "Show the help info of HotpotJVM")
            .addArgWithFlagAndName('v', "version", false, false, "Version flag", "Show the version of HotpotJVM")
            .addArgWithFlagAndName('c', "classpath", true, false, "classpath", "The user defined path of library")
            .addArgWithFlagAndName('j', "jre", true, true, "Jre path", "Jre path");

    try {
        cmd.parse();
        JVMStartInfo info{};

        // help
        if (argc == 1 || cmd.isDefined("-h")) {
            Args::HelpPrinter printer;
            printer.setExecutable("HotpotJVM");
            printer.setAppDescription("A Java Virtual Machine developed by thtTNT");
            printer.setLineLength(100);
            printer.setCmdLine(&cmd);
            printer.print(std::cout);
            return;
        }

        // version
        if (cmd.isDefined("-v")) {
            std::cout << "HotpotJVM Neko version 0.0.1";
            return;
        }

        // classpath
        if (cmd.isDefined("-c")) {
            info.classpath = cmd.value("-c");
            if (!tools::string::endWith(info.classpath, "/")) {
                info.classpath = info.classpath + "/";
            }
        } else {
            info.classpath = boost::filesystem::initial_path<boost::filesystem::path>().string() + "/";
        }

        //jre Path
        info.Xjre = cmd.value("-j");
        if (!tools::string::endWith(info.Xjre, "/")) {
            info.Xjre = info.Xjre + "/";
        }

        //handle className
        if (cmd.positional().size() == 0) {
            std::cout << "A class or --jar is required";
            return;
        } else {
            info.className = cmd.positional()[0];
            info.args = cmd.positional();
        }

        startJVM(info);

    } catch (Args::BaseException &exception) {
        std::cout << exception.desc() << std::endl;
    }
}


