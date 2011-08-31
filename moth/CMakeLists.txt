cmake_minimum_required(VERSION 2.8.4)

project(moth CXX)

add_definitions(-g -Wall -std=c++0x)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(mothlog_lib_src src/mothlog/consolelogger.cpp src/mothlog/filelogger.cpp src/mothlog/filerollerlogger.cpp src/mothlog/logger.cpp src/mothlog/loggerfactory.cpp)
set(mothutil_lib_src src/mothutil/mothexception.cpp src/mothutil/tokenizer.cpp src/mothutil/properties.cpp)
set(moththread_lib_src src/moththread/runnable.cpp src/moththread/thread.cpp src/moththread/mutex.cpp)
set(mothnet_lib_src src/mothnet/socket.cpp)

set(moth_lib_src ${mothutil_lib_src} ${mothlog_lib_src} ${moththread_lib_src} ${mothnet_lib_src})

include_directories(include src)
add_library(${PROJECT_NAME} SHARED ${moth_lib_src})
target_link_libraries(${PROJECT_NAME} pthread)

add_executable(tok src/test/tok.cpp)
target_link_libraries(tok moth)

add_executable(log src/test/log.cpp)
target_link_libraries(log moth)

add_executable(util src/test/util.cpp)
target_link_libraries(util moth)

add_executable(threads src/test/threads.cpp)
target_link_libraries(threads moth)
