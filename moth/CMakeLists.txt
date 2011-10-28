cmake_minimum_required(VERSION 2.8.4)

project(moth CXX)

add_definitions(-g -Wall -std=c++0x)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(mothlog_lib_src src/moth/log/consoleappender.cpp src/moth/log/fileappender.cpp src/moth/log/filerollerappender.cpp src/moth/log/logger.cpp src/moth/log/logappender.cpp)
set(mothutil_lib_src src/moth/util/mothexception.cpp src/moth/util/tokenizer.cpp src/moth/util/properties.cpp src/moth/util/clock.cpp)
set(moththread_lib_src src/moth/thread/thread.cpp src/moth/thread/mutex.cpp src/moth/thread/threadpool.cpp)
set(mothnet_lib_src src/moth/net/socket.cpp)

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
