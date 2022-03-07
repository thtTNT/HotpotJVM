cmake_minimum_required(VERSION 3.17)
project(HotpotJVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(HotpotJVM main.cpp Command.cpp exception/CommandParseError.cpp Command.h)