cmake_minimum_required(VERSION 3.17)
project(HotpotJVM)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)
conan_basic_setup()

add_executable(HotpotJVM src/main.cpp src/Command.cpp src/exception/CommandParseError.cpp src/Command.h src/classpath/entry.cpp src/classpath/entry.h src/classpath/ZipEntry.cpp src/classpath/ZipEntry.h src/exception/FileNotFoundException.cpp src/exception/FileNotFoundException.h src/classpath/DirEntry.cpp src/classpath/DirEntry.h src/classpath/CompositeEntry.cpp src/classpath/CompositeEntry.h src/utils/Utils.cpp src/utils/Utils.h src/classpath/Classpath.cpp src/classpath/Classpath.h src/exception/CommandParseError.h)
target_link_libraries(HotpotJVM ${CONAN_LIBS})